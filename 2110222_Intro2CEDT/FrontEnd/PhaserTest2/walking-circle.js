    const config = {
        type: Phaser.AUTO,
        width: 800,
        height: 600,
        scene: {
            preload: preload,
            create: create,
            update: update
        }
    };
    
    let player;
    let target = {x: 400, y: 300};
    let graphics;
    
    function preload() {
        // Preload assets if any
    }
    
    function create() {
        // Create graphics object for drawing
        graphics = this.add.graphics({ fillStyle: { color: 0xff0000 } });
    
        // Initial player position
        player = new Phaser.Geom.Circle(400, 300, 20);
        
        // Draw player
        graphics.fillCircleShape(player);
    
        // Setup input
        this.input.on('pointerup', function (pointer) {
            // Update target on click
            console.log(`Pointer lifted at x: ${pointer.x}, y: ${pointer.y}`);
            target.x = pointer.x;
            target.y = pointer.y;
        }, this);
    }
    
    function update() {
        if (target.x === undefined || target.y === undefined) return;
    
        // Move player towards target
        const distance = Phaser.Math.Distance.Between(player.x, player.y, target.x, target.y);
        console.log(`Distance to target (${target.x},${target.y}): ${distance}`);
        if (distance < 1) {
            target.x = undefined;
            target.y = undefined;
            // Stop moving when close to target
        } else {
            const angle = Phaser.Math.Angle.Between(player.x, player.y, target.x, target.y);
            player.x += Math.cos(angle) * 2; // Adjust speed as necessary
            player.y += Math.sin(angle) * 2; // Adjust speed as necessary
            graphics.clear(); // Clear previous frame
            graphics.fillCircleShape(player); // Draw player at new position
        }
    }
    
    let game = new Phaser.Game(config);