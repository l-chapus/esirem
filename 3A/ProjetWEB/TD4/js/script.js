window.addEventListener('load', () => {
    generateFields();
    attachToolsEvent();
});

function attachToolsEvent() {
    const tools = document.querySelectorAll('tool');

    for (let i = 0; i < tools.length; ++i) {
        tools[i].addEventListener("click", (event) => {
            for (let j = 0; j < tools.length; ++j) {
                if (event.target === tools[j])
                    tools[j].classList.add("active");
                else
                    tools[j].classList.remove("active");
            }
        })
    }
}

function arroser(){
    
}

function generateFields() {
    const fieldParts = document.querySelector('field-parts');

    for (let i = 0; i < 25; i++) {
        const fieldPart = document.createElement('field-part');
        fieldPart.classList.add('grass');
        fieldParts.appendChild(fieldPart);
    }
}