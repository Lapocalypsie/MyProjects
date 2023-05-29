function displayHour(){
    let now = new Date(); // Ici nous déclarons des variables que nous utiliserons pour stocker les valeurs nécéssaire
    charging_hour = now ;
    let dateinput = document.getElementById("date");
    let year = now.getYear() ;
    let date = now.getDate();
    let month = now.getMonth();
    if (now.getMinutes() < 10) {
        if (now.getHours()<10){ // On affiche le résultat en fonction des valeurs que nous avons.
            dateinput.value= ("Aujourd'hui nous sommes le "+ date + " /" +" 0"+ (month+1) +" / "
                + (year+1900) +" - "
                + " 0 "+ now.getHours() + "h" + "0"+now.getMinutes()) ;
        }
        else
        dateinput.value= ("Aujourd'hui nous sommes le "+ date + " /" + " 0"+ (month+1) +" / "
            + (year+1900) +" - "
            + now.getHours() + "h" + "0"+now.getMinutes()) ;
    }
    else
        dateinput.value= ("Aujourd'hui nous sommes le "+ date + " /" +" 0"+ + (month+1) +" / "
            + (year+1900) + " - "
            + now.getHours() + "h" + now.getMinutes()) ;
    dateinput.style.border="solid black"; // Ici nous décorons simplement, le temps données sur l'écran
    dateinput.style.fontSize="15px";
    dateinput.style.color="Blue";
    dateinput.style.fontStyle="Bold";
}

let changes_m = false ; // Nous définissons les variables hors de la fonction afin qu'elle reste la même lorsque
let sub_mail ; // la fonction sera appelée.

function inf(t) {
    if (!changes_m){  // ici on regarde si le mail a déjà été changée si oui alors on affecte une valeur modifié a submail
        sub_mail = "mailto:jimmy.rasolosoa@etu.univ-poitiers.fr?subject=" + navigator.userAgent ;
        changes_m =true;
    }
    let dates = new Date(); // On prend les données de navigation de l'utilisateur
    let secondes = dates.getSeconds() - charging_hour.getSeconds();
    t.href = sub_mail + " Le temps qui s'est passée est de : "+ secondes + "Secondes"; // on lui renvoie ses données
}

let card_color = ["Images/Citadelle.jpg","Images/Cluedo.jpg","Images/saboteur.png","Images/The_Mind.jpg"];
let ind_color = 0 ; // On crée un tableaun avec une indice qui nous permettra ensuite de changer les images.

function next_img() {
    let image = document.getElementById("img");
    ind_color--; // En modifiant l'indice, nous parcourons alors le tableau.
    if (ind_color < 0) {
        /* Lorsque le tableau arrive a la case 0, on remet l'indice a 3 pour pouvoir le refaire*/
        ind_color = 3;
    }
    image.src = card_color[ind_color]; // c'est ici que nous changeons la valeur afin de changer l'image.
}

function hide(a){
    let result = document.getElementById(a);
    if (result.style.display == "none"){
        /*c'est pour la liste, en fonction de la valeur de a on switch en none ou display.*/
        result.style.display = "block"
    }
    else {
        result.style.display = "none"
    }
}

/*On stocke les différent noms de notre tableau*/
let questions =["Temps = 5 minutes","Fabricateur du Jeu = Hasbro","Nombre de joueurs: 4 ou +",
    "Jeu de coopération","Jeu solitaire","Stratégique",
    "Nombre de joueurs 4 ou -","Temps 10 - 20 minutes","Temps 20 ou +"];

function report_miss () {
    let message = "";
    for(let i = 0 ; i < questions.length; i++){
        /*
           Parcours de la ligne i pour détecter si une réponse a été donnée à
           la question correspondante
        */
        let reponse = document.getElementsByName(questions[i]);
        /*
          La variable reponse est un tableau qui contient tous les éléments
          dont le nom est questions[i]
        */
        checked_answer = false;
        for (let j = 0 ; j < reponse.length; j++) {
            // parcours des différentes cases de la ligne i
            if (reponse[j].checked) {
                /* Dès que l'on trouve une case cochée dans la ligne, alors on
                   sait que le visiteur a répondu à cette question, on arrête
                   alors l'exploration de la ligne
                */
                checked_answer = true;
                break ;
            }
        }
        /*
           A cet endroit on a terminé l'examen des réponses à la question
           questions[i] et si le booléen checked_answer est toujours faux,
           cela signifie qu'il n'y a pas de réponse cochée
        */
        if (! checked_answer) {
            /* it message d'erreur pour dire qu'il manque une valeur
               sélectionnée dans la ligne de la question questions[i]
               (attention, tes questions sont numérotées Q1, Q2, etc.
               alors que dans le tableau question Q1 est questions[0])

            window.alert("Vous avez oublié de sélectionner une valeur dans: "
                + questions[i]);
             */
            message = message + ("Vous avez oublié de sélectionner une valeur dans: "
                + questions[i] + "\n");
            break ;
        }
    }
    window.alert(message);
}

function displayHour_1(){
    let now_1 = new Date(); // Ici nous déclarons des variables que nous utiliserons pour stocker les valeurs nécéssaire
    charging_hour = now_1 ;
    let dateinput_1 = document.getElementById("id_connexion");
    let year_1 = now_1.getYear() ;
    let date_1 = now_1.getDate();
    let month_1 = now_1.getMonth();
    if (now_1.getMinutes() < 10) {
        if (now_1.getHours()<10){ // On affiche le résultat en fonction des valeurs que nous avons.
            dateinput_1.value= (date_1 + " /" +" 0"+ (month_1+1) +" / "
                + (year_1+1900) +" - "
                + " 0 "+ now_1.getHours() + "h" + "0"+now_1.getMinutes()) ;
        }
        else
            dateinput_1.value= (date_1 + " /" + " 0"+ (month_1+1) +" / "
                + (year_1+1900) +" - "
                + now_1.getHours() + "h" + "0"+now_1.getMinutes()) ;
    }
    else
        dateinput_1.value= ( date_1 + " /" +" 0"+ + (month_1+1) +" / "
            + (year_1+1900) + " - "
            + now_1.getHours() + "h" + now_1.getMinutes()) ;
}
