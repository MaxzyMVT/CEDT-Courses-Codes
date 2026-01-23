package logic.unit;

public class FlyingUnit extends BaseUnit {
    public FlyingUnit(int startColumn, int startRow, boolean isWhite, String name) {
        super(startColumn, startRow, isWhite, name);
        setHp(2);
        isFlying = true;
    }

    @Override
    public boolean move(int direction) {

        int currentRow = getRow();
        int currentColumn = getColumn();
        boolean isMovable = switch (direction) {
            case 0 -> {
                setRow(currentRow + 2);
                yield getRow() - currentRow == 2;
            }
            case 1 -> {
                setColumn(currentColumn + 2);
                yield getColumn() - currentColumn == 2;
            }
            case 2 -> {
                setRow(currentRow - 2);
                yield currentRow - getRow() == 2;
            }
            case 3 -> {
                setColumn(currentColumn - 2);
                yield currentColumn - getColumn() == 2;
            }
            default -> false;
        };

        if(!isMovable) {
            setRow(currentRow);
            setColumn(currentColumn);
        }
        return isMovable;
    }
}
