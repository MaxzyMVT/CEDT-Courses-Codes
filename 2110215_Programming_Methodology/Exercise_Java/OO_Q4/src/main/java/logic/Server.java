package logic;

import java.util.ArrayList;

public class Server {
    String name;
    User owner;
    ArrayList<Channel> channelList;
    ArrayList<User> memberList;

    public Server(String name,User owner,TemplateType template) {
        this.owner = owner;
        this.memberList = new ArrayList<>();
        this.channelList = new ArrayList<>();
        this.addUser(owner);
        setName(name);
        String channelName = switch (template) {
            case BASIC -> "general";
            case GAMING -> "gaming";
            case STUDY -> "homework-help";
        };
        addChannel(owner, channelName);
    }

    public boolean isMemberInServer(User userToCheck) {
        return  getMemberList().contains(userToCheck);
    }

    public Channel addChannel(User user,String channelName) {
        if (!owner.equals(user)) {
            return null;
        }
        Channel channel = new Channel(channelName);
        getChannelList().add(channel);
        return channel;
    }

    public User addUser(User user) {
        if (isMemberInServer(user)) {
            return null;
        }
        getMemberList().add(user);
        user.addJoinedServersList(this);
        return user;
    }

    public boolean kickUser(User kicker, User kicked) {
        if (!owner.equals(kicker)) {
            throw new IllegalArgumentException("Unauthorized");
        }
        if(isMemberInServer(kicked) && !owner.equals(kicked)) {
            kicked.getJoinedServersList().remove(this);
            getMemberList().remove(kicked);
            return true;
        }
        return false;
    }

    public void setName(String name) {
        this.name = name.isBlank() ? owner.getName() + " home" : name;
    }

    public String getName() {
        return name;
    }

    public User getOwner() {
        return owner;
    }

    public ArrayList<Channel> getChannelList() {
        return channelList;
    }

    public ArrayList<User> getMemberList() {
        return memberList;
    }
}
