package game.piece;

import game.board.Board;
import game.position.Position;

public class Knight extends Piece {

    public Knight(boolean isWhite, Position pos, Board board) {
        super(isWhite, pos, board);
    }

    @Override
    public Object deepCopy() {
        Knight knight = new Knight(isWhite(), getPosition(), getBoard());
        knight.setMoved(isMoved());
        return knight;
    }
}
