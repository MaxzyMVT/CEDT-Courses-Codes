package logic;

import java.util.ArrayList;

public class Channel {
    private String name;
    private ArrayList<Message> messageList;

    public Channel(String name) {
        setName(name);
        messageList = new ArrayList<>();
    }

    public void addMessage(Message message) {
        getMessageList().add(message);
    }

    public int getMessageCount() {
        return getMessageList().size();
    }

    public void setName(String name) {
        this.name = name.isBlank() ? "off-topic" : name;
    }

    public String getName() {
        return name;
    }

    public ArrayList<Message> getMessageList() {
        return messageList;
    }
}
