window.addEventListener("load",() => {
    const aimants = document.querySelectorAll("aimant");
    aimants.forEach((aimant) => {
        aimant.addEventListener("click",mouvNounours);
    })
})

function mouvNounours(event)
{
    const aimant = event.target;
    const ours = document.querySelector("ours");

    if(aimant.classList.contains("left"))
    {
        const x = aimant.offsetLeft + aimant.clientWidth;
        ours.style.left = x + "px";
    }
    else
    {
        const x = aimant.offsetLeft - ours.clientWidth;
        ours.style.left = x + "px";
    }
}