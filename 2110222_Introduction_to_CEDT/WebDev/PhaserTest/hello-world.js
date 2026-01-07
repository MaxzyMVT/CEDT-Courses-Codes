const config = {
    type: Phaser.AUTO,
    width: 1080,
    height: 607.68,
    scene: {
        preload: preload,
        create: create
    }
};

let game = new Phaser.Game(config);

function preload() {
    // Loading images and other assets in this function
    this.load.image('watch', 'watch.jpg');
}

function create() {
    // Setting up the game world in this function
    this.add.image(540, 303.84, 'watch').setDisplaySize(1080, 607.68);
    this.add.text(500, 343.84, 'Chalermrach Thongkhaw', { fontSize: '32px', fill: '#FE0000', fontStyle: 'bold' }).setOrigin(0.5, 0.5);

}

function update() {
    // Code to run on every frame of the game
    // Nothing to run in this example
}