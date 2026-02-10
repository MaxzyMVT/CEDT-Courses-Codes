package main;

import gui.ControlGridPane;
import gui.ControlPane;
import gui.MineSweeperPane;
import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;
import logic.GameLogic;

public class Main extends Application {
	@Override
	public void start(Stage primaryStage) throws Exception {
		HBox root = new HBox();
		root.setPadding(new Insets(10));
		root.setSpacing(10);
		root.setPrefSize(800,400);

		MineSweeperPane MSPane = new MineSweeperPane();
		ControlPane CPane = new ControlPane(MSPane);
		ControlGridPane CGPane = new ControlGridPane(CPane);

		GameLogic.getInstance().setControlPane(CPane);
		root.getChildren().addAll(MSPane,CGPane);

		Scene scene = new Scene(root);
		primaryStage.setScene(scene);
		primaryStage.setTitle("MineSweeper");
		primaryStage.show();
	}

	public static void main(String[] args) {
		launch(args);
	}
}
