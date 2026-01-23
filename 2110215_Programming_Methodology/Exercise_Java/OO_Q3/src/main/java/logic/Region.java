package logic;

import java.util.ArrayList;

public class Region {
    private String name;
    private ArrayList<Player> playerList;
    private ArrayList<Quest> questList;

    public Region(String name) {
        setName(name);
        setPlayerList(new ArrayList<>());
        setQuestList(new ArrayList<>());
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name.isBlank() ? "Nowhere" : name;
    }

    public ArrayList<Player> getPlayerList() {
        return playerList;
    }

    public void setPlayerList(ArrayList<Player> playerList) {
        this.playerList = playerList;
    }

    public ArrayList<Quest> getQuestList() {
        return questList;
    }

    public void setQuestList(ArrayList<Quest> questList) {
        this.questList = questList;
    }

    public int getPlayerCount() {
        return getPlayerList().size();
    }

    public double getRegionRank() {
        double rankSum = 0;
        for (Player player : getPlayerList()) {
            rankSum += player.getRank();
        }
        return Math.round(rankSum / getPlayerCount() * 100D) / 100D ;
    }

    public ArrayList<Quest> getAvailableQuests(Player viewer) {
        ArrayList<Quest> availableQuests = new ArrayList<>();
        for (Quest quest : getQuestList()) {
            if (quest.getStatus().equals(Status.AVAILABLE) && !quest.getAuthor().equals(viewer)) {
                availableQuests.add(quest);
            }
        }
        return availableQuests;
    }

    public void addPlayerToRegion(Player player) {
        getPlayerList().add(player);
    }

    public void addQuestToRegion(Quest quest) {
        getQuestList().add(quest);
    }
}
