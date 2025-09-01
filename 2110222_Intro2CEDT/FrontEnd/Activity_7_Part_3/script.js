document.querySelector("#addbutton").addEventListener("click", function(event) {
    alert("The add button was clicked!")
})

const deleteButtonList = document.querySelectorAll(".deletebutton")
deleteButtonList.forEach(deleteButton => {
    deleteButton.addEventListener("click", handleClickDelete)
})

function handleClickDelete(event){
    const itemRow = event.target.parentElement.parentElement
    const itemName = itemRow.querySelector("td:nth-child(1)").textContent
    alert("The delete button ("+itemName+") was clicked!");
}

// An example of how to get the value of the input field
// Try executing this function in the console
function testGetInputValue() {
    alert(document.querySelector("#itemname-input").value)
}

// An example of how add a new row to the table
function testAddRow() {
    const table = document.querySelector("#itemlist-table")
    const newRow = document.createElement("tr")
    newRow.className = "item"
    newRow.innerHTML = "<td>ยุปปี้</td><td>นางสาวปุ๊บปิ๊บ มาใหม่</td><td>25</td><td><button class='deletebutton'>ลบ</button></td>"
    newRow.querySelector(".deletebutton").addEventListener("click", handleClickDelete)
    table.querySelector("tbody").appendChild(newRow)
}

// An example of how to remove a random row from the table
function testDeleteRandomRow(){
    const table = document.querySelector("#itemlist-table")
    const randomRowIndex = Math.floor(Math.random() * table.querySelectorAll(".item").length)
    const randomRow = table.querySelectorAll(".item")[randomRowIndex]
    randomRow.remove()
}

function addNewRow(){
    
    
   const itemInput = document.getElementById('itemname-input');
   const nameSelect = document.getElementById('name-to-add');
   const priceInput = document.getElementById('price-to-add');


   const item = itemInput.value.trim();
   const name = nameSelect.value;
   const price = priceInput.value.trim();


   const table = document.getElementById('itemlist-table');
   const newRow = document.createElement("tr");
   newRow.innerHTML = `
       <td>${item}</td>
       <td>${name}</td>
       <td>${price}</td>
       <td><button class="deletebutton">ลบ</button></td>
   `;
   newRow.querySelector(".deletebutton").addEventListener("click", handleClickDelete);
  
   table.querySelector("tbody").appendChild(newRow);


   itemInput.value = '';
   priceInput.value = '';
   itemInput.focus();


}


document.addEventListener('DOMContentLoaded', function() {
  
   document.getElementById('addbutton').addEventListener('click', addNewRow);
  
});


function handleClickDelete(event){
   const itemRow = event.target.parentElement.parentElement
   itemRow.remove()
}

