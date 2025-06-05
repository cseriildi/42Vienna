function getRandomColorValue() {
  return Math.floor(Math.random() * 256);
}

function setRandomBackgroundColor() {
  const red = getRandomColorValue();
  const green = getRandomColorValue();
  const blue = getRandomColorValue();

  document.body.style.backgroundColor = `rgb(${red}, ${green}, ${blue})`;
}

function handleClick() {
  setRandomBackgroundColor();

  buttonSize += 2;
  button.style.fontSize = `${buttonSize}px`;
}

let buttonSize = 8;
const button = document.getElementById("button");
button.addEventListener("click", handleClick);
