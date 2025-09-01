const deleteButtonList = document.querySelectorAll(".delete-row")
deleteButtonList.forEach(deleteButton => {
    deleteButton.addEventListener("click", handleClickDelete)
})

function handleClickDelete(event){
    const itemRow = event.target.parentElement.parentElement
    const itemName = itemRow.querySelector("td:nth-child(1)").textContent
    if (confirm(`คุณต้องการลบรายการ "${itemName}" หรือไม่?`)) {
        itemRow.remove()
        updateTotalDisplay()
    }
}

function testAddRow() {
    const table = document.querySelector("#main-table")
    const newRow = document.createElement("tr")
    newRow.className = "item"
    newRow.innerHTML = "<td>ยุปปี้</td><td>นางสาวปุ๊บปิ๊บ มาใหม่</td><td>25</td><td><button class='delete-row'>ลบ</button></td>"
    newRow.querySelector(".delete-row").addEventListener("click", handleClickDelete)
    table.querySelector("tbody").appendChild(newRow)
    updateTotalDisplay()
}

function testDeleteRandomRow(){
    const table = document.querySelector("#main-table")
    const itemRows = table.querySelectorAll("tbody tr")
    
    if (itemRows.length === 0) {
        alert("ไม่มีรายการให้ลบ!")
        return
    }
    
    const randomRowIndex = Math.floor(Math.random() * itemRows.length)
    const randomRow = itemRows[randomRowIndex]
    randomRow.remove()
    updateTotalDisplay()
}

function addNewRow(){
    const itemInput = document.getElementById('item-to-add')
    const nameSelect = document.getElementById('name-to-add')
    const priceInput = document.getElementById('price-to-add')

    const item = itemInput.value.trim()
    const name = nameSelect.value
    const price = priceInput.value.trim()

    if (!item || !price || isNaN(price) || parseFloat(price) <= 0) {
        alert("กรุณากรอกข้อมูลให้ครบถ้วนและถูกต้อง")
        return
    }

    const table = document.getElementById('main-table')
    const newRow = document.createElement("tr")
    newRow.innerHTML = `
        <td>${item}</td>
        <td>${name}</td>
        <td>${price}</td>
        <td><button class="delete-row">ลบ</button></td>
    `
    newRow.querySelector(".delete-row").addEventListener("click", handleClickDelete)
    
    table.querySelector("tbody").appendChild(newRow)

    itemInput.value = ''
    priceInput.value = ''
    itemInput.focus()
    
    updateTotalDisplay()
}

// ฟังก์ชันคำนวณจำนวนเงินรวมตามชื่อผู้ฝากซื้อ
function calculateTotalByPerson() {
    const table = document.querySelector("#main-table")
    const rows = table.querySelectorAll("tbody tr")
    const totals = {}
    
    rows.forEach(row => {
        const name = row.querySelector("td:nth-child(2)").textContent.trim()
        const price = parseFloat(row.querySelector("td:nth-child(3)").textContent)
        
        if (totals[name]) {
            totals[name] += price
        } else {
            totals[name] = price
        }
    })
    
    return totals
}

function updateTotalDisplay() {
    const totals = calculateTotalByPerson()
    const totalDiv = document.getElementById('total-summary')
    const totalContent = document.getElementById('total-content')
    
    let displayHTML = ""
    let grandTotal = 0
    
    for (const [name, total] of Object.entries(totals)) {
        displayHTML += `<p><strong>${name}:</strong> ${total} บาท</p>`
        grandTotal += total
    }
    
    displayHTML += `<hr><p style="font-size: 1.2em; color: #d9534f;"><strong>รวมทั้งหมด: ${grandTotal} บาท</strong></p>`
    
    totalContent.innerHTML = displayHTML
    
    
    if (Object.keys(totals).length > 0) {
        totalDiv.style.display = 'block'
    } else {
        totalDiv.style.display = 'none'
    }
}


function toggleTotalDisplay() {
    const totalDiv = document.getElementById('total-summary')
    
    if (totalDiv.style.display === 'none' || totalDiv.style.display === '') {
        updateTotalDisplay()
        totalDiv.style.display = 'block'
    } else {
        totalDiv.style.display = 'none'
    }
}

document.addEventListener('DOMContentLoaded', function() {
    
    document.getElementById('add-newrow').addEventListener('click', addNewRow)
    
    
    const showInfoButton = document.querySelector(".show_info")
    if (showInfoButton) {
        showInfoButton.addEventListener("click", toggleTotalDisplay)
    }
    
    
    const existingDeleteButtons = document.querySelectorAll(".delete-row")
    existingDeleteButtons.forEach(deleteButton => {
        deleteButton.addEventListener("click", handleClickDelete)
    })
    
    
    updateTotalDisplay()
    
    
    
})