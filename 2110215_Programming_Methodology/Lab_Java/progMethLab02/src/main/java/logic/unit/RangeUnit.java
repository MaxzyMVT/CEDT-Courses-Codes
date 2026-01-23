package logic.unit;

import java.util.ArrayList;

public class RangeUnit extends BaseUnit {
    public RangeUnit(int startColumn, int startRow, boolean isWhite, String name) {
        super(startColumn, startRow, isWhite, name);
        setHp(2);
    }

    @Override
    public void attack(ArrayList<BaseUnit> targetPieces) {
        int attackDirection = isWhite() ? 1 : -1;
        for (BaseUnit targetPiece : targetPieces) {
            if (targetPiece.getRow() == getRow() + attackDirection && targetPiece.getColumn() == getColumn()) {
                targetPiece.setHp(targetPiece.getHp() - getPower());
                System.out.println(this.getName() + " attacks " + targetPiece.getName());
            }
        }
    }
}
