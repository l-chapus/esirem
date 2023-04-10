window.addEventListener("load",() => {
    start();
})

function start()
{
    let variable2 = 20;

    const constante = [];
    constante.push("toto");
    constante.push(45);

    console.log("Variable2 : " + variable2);
    console.log(constante);

    constante.forEach((item,index) => {
        console.log(index + " : "+item)
    })


    constante.splice(0,1);
    console.log(constante);

    const body = document.querySelector(".class");
    console.log(body)


}