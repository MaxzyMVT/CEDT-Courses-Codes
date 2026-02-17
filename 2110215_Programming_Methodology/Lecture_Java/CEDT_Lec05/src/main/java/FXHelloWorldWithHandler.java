import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.StackPane;
import javafx.scene.control.Button;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;

import java.awt.event.MouseEvent;

public class FXHelloWorldWithHandler extends Application {
    int count =0;
    // Override the start method in the Application class
    @Override
    public void start(Stage primaryStage) {
        // Create a scene and place a button in the scene
        Button btn = new Button("Hello world");
        btn.setId("helloButton");

        // set event handler
        btn.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent event) {
                count++;
                btn.setText("Hello World " + count);
            }
        });

        // Short-form notation of event handler
        /**
         Because there is only 1 abstract method in interface EventHandler (Functional Interface)
         */
        btn.setOnMouseEntered(e -> {
            System.out.println("Wow!!!");
            System.out.println("Mouse Entered!!!");
        });

        btn.setOnMouseExited(e -> System.out.println("Mouse Exited!!!"));

        StackPane root = new StackPane();
        root.getChildren().add(btn);
        Scene scene = new Scene(root, 300, 250);
        primaryStage.setTitle("MyJavaFX"); // Set the stage title
        primaryStage.setScene(scene); // Place the scene
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
