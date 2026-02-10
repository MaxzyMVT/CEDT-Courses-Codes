package logic.stone;

import logic.game.GameManager;
import utils.GameUtilities;

public class WalkingStone extends Stone {
    public WalkingStone(int posX, int posY) {
        super(posX, posY);
    }

    @Override
    public void dig(int digPower) {
        super.dig(digPower);
        if(digPower > 1) {
            GameManager gm = GameManager.getInstance();
            gm.setGameScore(gm.getGameScore() + 1);
        }
    }

    public void walk() {
        GameUtilities.moveWalkingRock(this);
    }
}
