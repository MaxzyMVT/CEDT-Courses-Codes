package logic.unit;

import java.awt.*;
import java.util.ArrayList;

public class BaseUnit {
    private int row;
    private int column;
    private boolean isWhite;
    private String name;
    protected int hp;
    protected int power;
    protected boolean isFlying;

    public BaseUnit(int startColumn, int startRow, boolean isWhite, String name) {
        setRow(startRow);
        setColumn(startColumn);
        setWhite(isWhite);
        setName(name);
        setHp(2);
        this.power = 1;
        this.isFlying = false;
    }

    public boolean move(int direction) {

        int currentRow = getRow();
        int currentColumn = getColumn();
        return switch (direction) {
            case 0 -> {
                setRow(currentRow + 1);
                yield currentRow != getRow();
            }
            case 1 -> {
                setColumn(currentColumn + 1);
                yield currentColumn != getColumn();
            }
            case 2 -> {
                setRow(currentRow - 1);
                yield currentRow != getRow();
            }
            case 3 -> {
                setColumn(currentColumn - 1);
                yield currentColumn != getColumn();
            }
            default -> false;
        };
    }

    public void attack(ArrayList<BaseUnit> targetPieces) {
        for (BaseUnit targetPiece : targetPieces) {
            if(!targetPiece.isFlying && targetPiece.getRow() == getRow() && targetPiece.getColumn() == getColumn()) {
                targetPiece.setHp(targetPiece.getHp() - getPower());
                System.out.println(this.getName() + " attacks " + targetPiece.getName());
            }
        }
    }

    public int getRow() {
        return row;
    }

    public void setRow(int row) {
        this.row = Math.max(0, Math.min(4, row));
    }

    public int getColumn() {
        return column;
    }

    public void setColumn(int column) {
        this.column = Math.max(0, Math.min(4, column));
    }

    public boolean isWhite() {
        return isWhite;
    }

    public void setWhite(boolean white) {
        isWhite = white;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getHp() {
        return hp;
    }

    public void setHp(int hp) {
        this.hp = hp;
    }

    public int getPower() {
        return power;
    }

    public boolean isFlying() {
        return isFlying;
    }
}
