// scripts.js

const changeColorButton = document.getElementById('changeColorButton');
const colorText = document.getElementById('colorText');

changeColorButton.addEventListener('click', function () {
  const newColor = getRandomColor();
  colorText.style.color = newColor;
  colorText.innerHTML = `Color: ${newColor}`;
});
