package piece;

import board.Board;
import position.Position;
import util.Movement;

import java.util.Set;

public class Piece {
    protected boolean white;
    protected boolean moved;
    protected Position position;
    protected Board board;

    public Piece(boolean white, Position position, Board board) {
        setWhite(white);
        setMoved(false);
        setPosition(position);
        setBoard(board);
    }

    public Set<Position> getLegalMove() {
        Movement move = new Movement(getPosition(), getBoard());
    }

    public boolean isWhite() {
        return white;
    }

    public void setWhite(boolean white) {
        this.white = white;
    }

    public boolean isMoved() {
        return moved;
    }

    public void setMoved(boolean moved) {
        this.moved = moved;
    }

    public Position getPosition() {
        return position;
    }

    public void setPosition(Position position) {
        this.position = position;
    }

    public Board getBoard() {
        return board;
    }

    public void setBoard(Board board) {
        this.board = board;
    }
}
