package gui;

import javafx.geometry.Pos;
import javafx.scene.layout.GridPane;
import logic.Command;

public class CommandControllerPane extends GridPane {

    public CommandControllerPane(){
        CommandArrowPane upPane = new CommandArrowPane(Command.UP);
        CommandArrowPane leftPane = new CommandArrowPane(Command.LEFT);
        CommandArrowPane rightPane = new CommandArrowPane(Command.RIGHT);
        CommandArrowPane downPane = new CommandArrowPane(Command.DOWN);

        add(upPane,1,0);
        add(leftPane,0,1);
        add(rightPane,2,1);
        add(downPane,1,2);

        //No code change below this point.
        this.setAlignment(Pos.CENTER);

        setHgap(10);
        setVgap(10);

        setPrefHeight(200);
        setPrefWidth(200);
    }

}
