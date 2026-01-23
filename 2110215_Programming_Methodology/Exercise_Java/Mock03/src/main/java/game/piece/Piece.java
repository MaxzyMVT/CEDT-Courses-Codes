package game.piece;

import game.board.Board;
import game.position.Position;
import game.util.Movement;

import java.util.Objects;
import java.util.Set;

public abstract class Piece {
    protected boolean white;
    protected boolean moved;
    protected Position position;
    protected Board board;

    public Piece(boolean white, Position position, Board board) {
        setWhite(white);
        setMoved(false);
        setPosition(position);
        setBoard(board);
        board.placePiece(this, position);
    }

    public Set<Position> getLegalMove() {
        Movement move = new Movement(getPosition(), getBoard());
        move.getMovePositions(this);
        return move.getMoves();
    }

    public abstract Object deepCopy();

    @Override
    public String toString() {
        return getClass().getSimpleName() + "(" + getPosition() + ")";
    }

    public void moveHandle(Position to) {
        hadMoved();
        setPosition(to);
    }

    public void hadMoved() {
        setMoved(true);
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Piece piece = (Piece) o;
        return isWhite() == piece.isWhite() && isMoved() == piece.isMoved() && getPosition().equals(piece.getPosition()) && getBoard().equals(piece.getBoard());
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
