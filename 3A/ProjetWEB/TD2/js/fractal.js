function onClick()
{
    console.log(`Click !`)
    const xCenter = document.querySelector("#xCenter").value
    const yCenter = document.querySelector("#yCenter").value
    const zoom = document.querySelector("#zoom").value
    const maxIteration = document.querySelector("#maxIteration").value
    fetch(`http://57.128.111.226?xCenter=${xCenter}&yCenter=${yCenter}&zoom=${zoom}&maxIteration=${maxIteration}`)
    .then((response) => {
        response.text().then((data) => {
            document.querySelector("div").innerHTML = data
    }).catch((error) =>
    {
        console.log(error)
    })
}). catch((error) =>
{
console.log(error)
})

}
const btnGetIT = document.querySelector("button")
btnGetIT.addEventListener("click", onClick)