package logic.stone;

import utils.GameUtilities;

import java.util.ArrayList;

public class Dynamite extends Stone{
    public Dynamite(int posX, int posY) {
        super(posX, posY);
    }

    @Override
    public void destroy() {
        super.destroy();

        ArrayList<Stone> adjStones = GameUtilities.getAdjacentStones(getPosX(), getPosY());
        for(Stone stone : adjStones){
            stone.destroy();
        }
    }
 }
