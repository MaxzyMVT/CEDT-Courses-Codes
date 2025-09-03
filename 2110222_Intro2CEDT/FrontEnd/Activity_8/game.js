class RoomUtil {
  static baseURL = "https://demo.mycourseville.com/act6/";
  static roomApiURL = `${RoomUtil.baseURL}roomapi/`;
  static ROOMSIZE = { w: 800, h: 600 };
  static isReady = false;

  // It might be useful for the "players" object to be used for storing all the players in the room. The key could be the player's number and the value could be the Player object.
  static players = {};

  static getSecret() {
    const urlParams = new URLSearchParams(window.location.search);
    return urlParams.get("secret") || null;
  }
  static getPlayerNumber() {
    const urlParams = new URLSearchParams(window.location.search);
    return urlParams.get("player") || null;
  }

  static getInitAndStartGames(scene, myPlayer) {
    // Fetch the initial player look data from the server
    fetch(`${RoomUtil.roomApiURL}getplayerlook.php`, {
      method: "GET",
      headers: {
        "X-Secret": RoomUtil.getSecret(),
      },
    })
      .then((response) => response.json())
      .then((data) => {
        // Let RoomUtil.initAllPlayers() handle the initialization of the players based on data.
        RoomUtil.initAllPlayers(scene, data, myPlayer);

        // For Part 3:
        // Once we have the Player objects, we can start fetching the player position data from the server
        RoomUtil.fetchAllPlayersXY(scene);
      })
      .catch((error) =>
        console.error("Error fetching player look data:", error)
      );
  }

  static initAllPlayers(scene, data, myPlayer) {
    // Part 1 & 2: Iterate through the look data, instantiate Player objects,
    // and use the myPlayer instance for the user's own player.
    Object.keys(data).forEach((key) => {
      const playerData = data[key]; // playerData is the look object, e.g., {shape: 'circle', color: 'red'}
      let player;

      if (key === myPlayer.playerNumber) {
        // If the player is the current user, use the pre-created MyPlayer object.
        player = myPlayer;
      } else {
        // If the player is not the current user, create a new Player object.
        player = new Player(key);
      }

      // Initialize the player's appearance and create the visual graphics object in the scene.
      player.initLookAndVisual(scene, playerData);

      // Add the player to the RoomUtil.players object for global access.
      RoomUtil.players[key] = player;
    });

    // Set the ready flag to true so the main update loop can start.
    RoomUtil.isReady = true;
  }

static fetchAllPlayersXY(scene) {
    // Part 3: Fetch the position/target data for all players from the server.
    fetch(`${RoomUtil.roomApiURL}getplayerxy.php`, {
      method: "GET",
      headers: {
        "X-Secret": RoomUtil.getSecret(),
      },
    })
      .then((response) => response.json())
      .then((data) => {
        // Once the position data is fetched, update the local Player objects.
        Object.keys(data).forEach((key) => {
          
          // *** THE FIX IS HERE ***
          // We must not update our own player with data from the server,
          // because our local input is the authority. We only update OTHER players.
          if (key === `p${RoomUtil.getPlayerNumber()}`) {
            return; // This skips the rest of the code for this iteration of the loop.
          }

          const playerFromServer = data[key];
          const playerInRoom = RoomUtil.players[key];

          if (playerInRoom) {
            
            playerInRoom.setTarget(parseFloat(playerFromServer.target_x), parseFloat(playerFromServer.target_y));
          }
        });
      })
      .catch((error) =>
        console.error("Error fetching player XY data:", error)
      );
  }
}

class Player {
  // Represents a player in the game
  constructor(playerNumber) {
    this.playerNumber = playerNumber;
    this.look = null; // The look of the player. This is an object with shape and color properties
    this.visual = null; // The Phaser visual representation (graphics object) of the player
    
    // Part 1: Assign a random initial position within the room dimensions.
    this.posX = Math.random() * RoomUtil.ROOMSIZE.w;
    this.posY = Math.random() * RoomUtil.ROOMSIZE.h;
    this.targetX = this.posX;
    this.targetY = this.posY;
  }

  // Convert color names to hex codes
  getHexFromColorName(colorName) {
    const colorMap = {
      purple: 0x800080,
      blue: 0x0000ff,
      red: 0xff0000,
      orange: 0xffa500,
      yellow: 0xffff00,
      green: 0x008000,
    };
    return colorMap[colorName.toLowerCase()] || 0x000000;
  }

  initLookAndVisual(scene, look) {
    this.look = look;
    const color = this.getHexFromColorName(look.color);

    if (look.shape === "circle") {
      this.visual = scene.add.circle(this.posX, this.posY, 10, color);
    } else if (look.shape === "square") {
      this.visual = scene.add.rectangle(this.posX, this.posY, 20, 20, color);
    } else {
      // Default look if data is missing or invalid
      this.visual = scene.add.circle(this.posX, this.posY, 10, 0xff0000);
    }
  }

  setPosition(x, y) {
    this.posX = x;
    this.posY = y;
    // Update the visual representation's position if it exists
    if (this.visual) {
      this.visual.setPosition(this.posX, this.posY);
    }
  }

  setTarget(x, y) {
    this.targetX = x;
    this.targetY = y;
  }

  // Call this method every frame to smoothly update the player's position
  updatePlayerInRoom() {
    // If this player doesn't have a visual representation, we can't do anything.
    if (!this.visual) {
      return;
    }

    // Check if the player has a valid target to move towards.
    // If targetX is undefined, it means the player should not be moving.
    if (this.targetX === undefined || this.targetY === undefined) {
      return;
    }

    const speed = 2; // You can adjust this value for faster or slower movement.

    // Calculate the distance between the player's current position and its target.
    const distance = Phaser.Math.Distance.Between(this.posX, this.posY, this.targetX, this.targetY);

    // If the player is very close to the target, snap it to the exact destination
    // and clear the target so it stops moving.
    if (distance < speed) {
      this.posX = this.targetX;
      this.posY = this.targetY;
      
      // Clear the target so the movement stops.
      // Important: Don't do this for other players, only for myPlayer,
      // as other players' targets are controlled by the server.
      if (this instanceof MyPlayer) {
          this.targetX = undefined;
          this.targetY = undefined;
      }

    } else {
      // If the player is still far from the target, calculate the angle and move it.
      // The key is using 'this' to get the properties of the CURRENT player instance.
      const angle = Phaser.Math.Angle.Between(this.posX, this.posY, this.targetX, this.targetY);

      // Update the player's internal position data.
      this.posX += Math.cos(angle) * speed;
      this.posY += Math.sin(angle) * speed;
    }

    // Finally, update the on-screen graphic to match the player's new internal position.
    this.visual.setPosition(this.posX, this.posY);
  }
}

class MyPlayer extends Player {
  // Represents the player controlled by the current user
  constructor(secret, playerNumber) {
    super(playerNumber);
    this.secret = secret;
  }

  setTarget(x, y) {
    super.setTarget(x, y);
    // When the user clicks to set a new target, immediately update the server.
    this.updateMyselfToServer();
  }

  updateMyselfToServer() {
    // Part 2: Send the new position and target to the server via a POST request.
    // The request body must be formatted as 'application/x-www-form-urlencoded'.
    const requestBody = new URLSearchParams({
      pos_x: this.posX,
      pos_y: this.posY,
      target_x: this.targetX,
      target_y: this.targetY,
    });

    fetch(`${RoomUtil.roomApiURL}update.php`, {
      method: "POST",
      headers: {
        "X-Secret": this.secret,
        "Content-Type": "application/x-www-form-urlencoded",
      },
      body: requestBody.toString(),
    })
    .then(response => response.json())
    .then(data => {
        if (!data.success) {
            console.error("Failed to update player data on server:", data);
        }
    })
    .catch((error) => console.error("Error updating player data:", error));
  }

  initLookAndVisual(scene, look) {
    // First, call the parent method to create the basic shape.
    super.initLookAndVisual(scene, look);

    // Part 2: Override the parent method so that your player has a thick black border.
    if (this.visual) {
      this.visual.setStrokeStyle(4, 0x000000); // Add a thick black border
    }
  }
}

// --- Phaser Game Setup ---
let game, myPlayer;
// Use a scene-level variable for the timer instead of a global one.
let fetchInterval = 5000; // Fetch data every 5 seconds

const secret = RoomUtil.getSecret();
const playerNumber = RoomUtil.getPlayerNumber();

if (!secret) {
  alert("No secret provided. Please add ?secret=YOUR_SECRET to the URL.");
} else if (!playerNumber) {
  alert("No player number provided. Please add &player=YOUR_PLAYER_NUMBER to the URL.");
} else {
  const config = {
    type: Phaser.AUTO,
    width: RoomUtil.ROOMSIZE.w,
    height: RoomUtil.ROOMSIZE.h,
    parent: "gameContainer",
    scene: {
      preload: preload,
      create: create,
      update: update,
    },
  };
  game = new Phaser.Game(config);
  // Create an instance of MyPlayer for the user.
  myPlayer = new MyPlayer(secret, playerNumber);
}

function preload() {
  this.load.image("background", "assets/gridbg.png");
}

function create() {
  // Add background image
  this.add.image(RoomUtil.ROOMSIZE.w / 2, RoomUtil.ROOMSIZE.h / 2, "background");

  // Initialize a timer for fetching data periodically.
  this.lastFetchTime = 0;

  // Set up the click event listener to move the player.
  this.input.on("pointerdown", (pointer) => {
    myPlayer.setTarget(pointer.x, pointer.y);
  });

  // Start the process of fetching player looks and then positions.
  RoomUtil.getInitAndStartGames(this, myPlayer);
}

function update(time, delta) {
  if (RoomUtil.isReady) {

    Object.values(RoomUtil.players).forEach((player) => {
      player.updatePlayerInRoom();
    });

    // This part remains the same for fetching server updates periodically.
    this.lastFetchTime += delta;
    if (this.lastFetchTime >= fetchInterval) {
      this.lastFetchTime = 0;
      // Fetch the current player data from the server
      RoomUtil.fetchAllPlayersXY(this);
    }
  }
}