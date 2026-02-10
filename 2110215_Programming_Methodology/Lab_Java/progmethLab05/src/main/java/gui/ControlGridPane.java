package gui;

import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;

public class ControlGridPane extends GridPane {
    private final String miningImageURL;
    private ControlPane controlPane;

    public ControlGridPane(ControlPane controlPane) {
        this.miningImageURL = "bitcoin.png";
        this.controlPane = controlPane;

        ImageView imgV = new ImageView(miningImageURL);
        imgV.setFitHeight(150);
        imgV.setFitWidth(150);

        BorderPane borderPane = new BorderPane();
        borderPane.setPrefSize(150, 200);

        borderPane.setCenter(imgV);
        add(borderPane, 0, 0);
        add(this.controlPane, 0, 1);
    }
}
