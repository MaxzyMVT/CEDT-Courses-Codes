package gui;

import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import logic.GameLogic;

public class ControlPane extends VBox {
    private Text gameText;
    private Button newGameButton;
    private Button secureModeButton;
    private MineSweeperPane mineSweeperPane;

    public ControlPane(MineSweeperPane mineSweeperPane) {
            this.mineSweeperPane = mineSweeperPane;
            setAlignment(Pos.CENTER);
            setPrefWidth(300);
            setSpacing(20);

            initializeGameText();
            initializeNewGameButton();
            initializeSecureModeButton();
            getChildren().addAll(gameText, newGameButton, secureModeButton);
    }

    private void initializeGameText() {
        gameText = new Text("Tiles left : " + GameLogic.getInstance().getTileCount());
        gameText.setFont(new Font(35));
    }

    public void updateGameText(String text) {
        gameText.setText(text);
    }

    private void initializeNewGameButton() {
        newGameButton = new Button("New Game");
        newGameButton.setPrefWidth(100);
        newGameButton.setOnAction(event -> newGameButtonHandler());
    }

    private void initializeSecureModeButton() {
        secureModeButton = new Button("Secure mode : OFF");
        secureModeButton.setPrefWidth(150);
        secureModeButton.setOnAction(event -> secureModeButtonHandler());
    }

    private void newGameButtonHandler() {
        GameLogic gl = GameLogic.getInstance();
        gl.newGame();

        secureModeButton.setText("Secure mode : OFF");
        gameText.setText("Tiles left : "+ gl.getTileCount());
        for (MineSweeperSquare square : mineSweeperPane.getAllCells()) {
            square.initializeCellColor();
        }
    }

    private void secureModeButtonHandler() {
        GameLogic gl = GameLogic.getInstance();
        gl.toggleSecureMode();

        if(gl.isSecureMode()) {
            secureModeButton.setText("Secure mode : ON");
        } else {
            secureModeButton.setText("Secure mode : OFF");
        }
    }
}
