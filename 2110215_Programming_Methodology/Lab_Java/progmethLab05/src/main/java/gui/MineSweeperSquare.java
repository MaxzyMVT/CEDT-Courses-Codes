package gui;

import javafx.scene.image.Image;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.BackgroundImage;
import javafx.scene.layout.BackgroundSize;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import logic.GameLogic;
import logic.SquareMark;
import logic.SquareState;
import javafx.event.EventHandler;
import javafx.geometry.Insets;

public class MineSweeperSquare extends Pane{
	private boolean isDrawn;
	private Color baseColor;
	private int xPosition;
	private int yPosition;
	private final String oURL;
	private final String oneURL;
	private final String mineURL;
	private final String flagURL;

	public MineSweeperSquare(int x, int y) {
		oURL = "o.png";
		oneURL = "one.png";
		mineURL = "mine.png";
		flagURL = "flag.png";
		setxPosition(x);
		setyPosition(y);
		setPrefSize(100,100);
		setMinSize(100,100);
		setBaseColor(Color.MOCCASIN);
		initializeCellColor();
		setOnMouseClicked(event -> onClickHandler());
	}

	private void onClickHandler() {
		GameLogic gl = GameLogic.getInstance();
		if(!gl.isGameEnd()) {
			if(!gl.isSecureMode() && gl.getBoardState()[xPosition][yPosition] != SquareState.REVEALED) {
				switch(gl.getBoardMark()[xPosition][yPosition]) {
						case ONE -> draw(new Image(oneURL), Color.ORANGE);
						case NOTHING -> draw(new Image(oURL), Color.YELLOW);
						case MINE -> draw(new Image(mineURL), Color.RED);
				}
				gl.updateState(xPosition, yPosition, SquareState.REVEALED);
			}
			else if(gl.isSecureMode() && !isDrawn) {
				draw(new Image(flagURL), Color.GREEN);
				gl.updateState(xPosition, yPosition, SquareState.SECURED);
			}
		}
	}

	private void draw(Image image, Color backgroundColor) {
		BackgroundFill bgFill = new BackgroundFill(backgroundColor, CornerRadii.EMPTY, Insets.EMPTY);
		BackgroundFill[] bgFillA = {bgFill};
		BackgroundSize bgSize = new BackgroundSize(100,100,false,false,false,false);
		BackgroundImage bgImg = new BackgroundImage(image, null, null, null, bgSize);
		BackgroundImage[] bgImgA = {bgImg};
		this.setBackground(new Background(bgFillA,bgImgA));

		setDrawn(true);
	}

	public void initializeCellColor() {
		this.setBackground(new Background(new BackgroundFill(
				baseColor,
				CornerRadii.EMPTY,
				Insets.EMPTY
		)));
		setDrawn(false);
	}

	public boolean isDrawn() {
		return isDrawn;
	}

	public void setDrawn(boolean drawn) {
		isDrawn = drawn;
	}

	public Color getBaseColor() {
		return baseColor;
	}

	public void setBaseColor(Color baseColor) {
		this.baseColor = baseColor;
	}

	public int getxPosition() {
		return xPosition;
	}

	public void setxPosition(int xPosition) {
		this.xPosition = xPosition;
	}

	public int getyPosition() {
		return yPosition;
	}

	public void setyPosition(int yPosition) {
		this.yPosition = yPosition;
	}

	public String getoURL() {
		return oURL;
	}

	public String getOneURL() {
		return oneURL;
	}

	public String getMineURL() {
		return mineURL;
	}

	public String getFlagURL() {
		return flagURL;
	}
}
