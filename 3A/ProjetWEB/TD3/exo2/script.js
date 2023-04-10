window.addEventListener("load",() => {
    const left = document.querySelectorAll("left");
    const right = document.querySelectorAll("right");

    left.addEventListener("click", previous);
    right.addEventListener("click", next);
})

function previous()
{
    const picture = document.querySelector("picture");
    const code = document.querySelector("code > span");

    let hexValue = code.innerText;
    let decValue = parseInt(hexValue, 16);

    --decValue

    hexValue = decValue.toString(16);

    code.innerText = hexValue;
    picture.innerHTML = "&#x" + hexValue + ";";
}
function next ()
{
    
}