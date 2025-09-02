const config = {
    type: Phaser.AUTO,
    width: 108,
    height: 44,
    backgroundColor: '#dddddd', 
    scene: {
        preload: preload,
        create: create
    }
};

function preload() {
    // Load two different sprite sheets for the players
    this.load.spritesheet('player1', 'assets/DinoSprites - doux.png', { frameWidth: 24, frameHeight: 24 });
    this.load.spritesheet('player2', 'assets/DinoSprites - mort.png', { frameWidth: 24, frameHeight: 24 });
}

function create() {
    // Create animations for each player
    this.anims.create({
        key: 'walk1',
        frames: this.anims.generateFrameNumbers('player1', { start: 0, end: 24 }),
        frameRate: 10,
        repeat: -1
    });
    this.anims.create({
        key: 'walk2',
        frames: this.anims.generateFrameNumbers('player2', { start: 0, end: 24 }),
        frameRate: 10,
        repeat: -1
    });

    // Array to hold the player sprites
    let players = [];

    // Add the first player sprite, animate it with 'walk1'
    players.push(this.add.sprite(20, 20, 'player1').play('walk1'));

    // Add the second player sprite, animate it with 'walk2'
    let player2 = this.add.sprite(64, 20, 'player2').play('walk2');
    player2.flipX = true; // Flip the sprite horizontally
    players.push(player2);
}

const game = new Phaser.Game(config);