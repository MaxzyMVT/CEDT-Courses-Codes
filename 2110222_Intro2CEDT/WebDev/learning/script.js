        // script.js
        let clickCount = 0;

        document.addEventListener("DOMContentLoaded", function() {
        const addItemButton = document.getElementById("addItemButton");
        addItemButton.addEventListener("click", addListItem);
        });

        function addListItem() {
        clickCount++;
        
        const itemList = document.getElementById("itemList");
        const newItem = document.createElement("li");
        newItem.textContent = "Explore JavaScript " + clickCount + " times";
        itemList.appendChild(newItem);
        }