window.addEventListener('load', () => {

    const texte = document.getElementById("texte");

    const boutton = document.getElementById("texte_bouton");
    boutton.addEventListener("click", function () {
    
        //console.log(texte.value);

        //Enregistrer une donnée : 
        sessionStorage.setItem("texte_bouton", texte.value);
    });


    //Lire une information (si la clé n’existe pas, valeur vaudra null): 
    const texte_local = sessionStorage.getItem("texte_bouton");
    
    if(texte_local != null){
        texte.value = texte_local;
    }

    

});

