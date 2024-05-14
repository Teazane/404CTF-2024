# 404 CTF 2024
**Présentation de l'évènement**
>  Coorganisé par la Direction Générale de la Sécurité Extérieure (DGSE) et le club de cybersécurité HackademINT de Télécom SudParis, le 404 CTF est la plus grande compétition de cybersécurité de France. Après le succès de l'édition 2022 qui célébrait le double anniversaire du BCRA et de la DGSE, et de l'édition 2023 qui mettait à l'honneur les grandes figures de la littérature française, le 404 CTF présentait en 2024 sa 3e édition célébrant le monde du sport. La compétition s'étendait du 20 avril 2024 au 12 mai 2024.

Ci-dessous, mes notes prises durant la compétition au cours de laquelle mon meilleur classement a été 221e, et mon classement final 946e (avec un score de 1010 points) sur un total de 3271 participant.e.s.

![Score final](Final.png)

Les challenges non-terminés (notés "Pas fini") sont agrémentés d'une note expliquant la solution, établie après la lecture des Write Ups d'autres participants (avec un lien vers leur page pour plus de détails).

Challenges essayés :
- [404 CTF 2024](#404-ctf-2024)
   * [Divers](#divers)
      + [Bienvenue (Intro)](#bienvenue-intro)
      + [Discord (Intro)](#discord-intro)
   * [Renseignement en source ouverte (OSINT)](#renseignement-en-source-ouverte-osint)
      + [Légende (Intro)](#légende-intro)
      + [Not on my watch (Facile)](#not-on-my-watch-facile)
   * [Web](#web)
      + [Vous êtes en RETARD (Intro)](#vous-êtes-en-retard-intro)
      + [Le match du siècle [1/2] (Intro)](#le-match-du-siècle-12-intro)
      + [Exploit mag (facile) - Pas fini](#exploit-mag-facile---pas-fini)
   * [Investigation numérique](#investigation-numérique)
      + [Le tir au logs (Intro)](#le-tir-au-logs-intro)
      + [Darts bank (Moyen) - Pas fini](#darts-bank-moyen---pas-fini)
   * [Stéganographie](#stéganographie)
      + [L'absence (Intro)](#labsence-intro)
      + [Regarder en stéréo (Facile)](#regarder-en-stéréo-facile)
      + [La barre fixe (Facile mais seulement 22 flags =.=') - Pas fini](#la-barre-fixe-facile-mais-seulement-22-flags----pas-fini)
      + [Le grand écart (Moyen) - Pas fini](#le-grand-écart-moyen---pas-fini)
      + [La chute (Moyen) - Pas fini](#la-chute-moyen---pas-fini)
   * [Rétro-ingénierie (reverse)](#rétro-ingénierie-reverse)
      + [Echauffement (Intro) - Pas fini](#echauffement-intro---pas-fini)

## Divers
### Bienvenue (Intro)
Le flag est caché dans la page du règlement : 404CTF{0n_0ubl13_p45_d3_S3cH4ufF3r}.

### Discord (Intro)
Le flag est caché dans une des annonces de 404 BOT, celle du 19 avril à 19h : 404CTF{C'estparti!une!deux!une!deux}.

## Renseignement en source ouverte (OSINT)
### Légende (Intro)
On nous donne la photo "photo.png" : 
![Légende](/OSINT/photo.png)

et l'intitulé suivant : 
> Sur cette photo, une des premières légendes du ski français s'apprête à franchir la ligne d'arrivée et remporter son troisième titre de champion du monde cette année. Saurez-vous retrouver son nom et prénom ainsi que le nom de la ville dans laquelle ces compétitions ont eu lieu ?

En cherchant sur la page Wiki des champions français de ski on trouve trois athlètes avec un palmarès >= 3 en championnat du monde : 
- https://fr.wikipedia.org/wiki/%C3%89mile_Allais né en 1912
- https://fr.wikipedia.org/wiki/Jean-Claude_Killy né en 1943
- https://fr.wikipedia.org/wiki/Marielle_Goitschel née en 1945

J'ai mal lu l'énoncé en fait. C'est le 3e titre mondial *de l'année*. 
- Marielle Goitschel a remporté trois titres en 1966 à Portillo au Chili (mais sur la photo, on dirait bien un drapeau tricolor accroché à la ligne d'arrivée).
- J-C Killy a remporté quatre titres en 1968 à Grenoble (mais c'était des JO).
- Emile Allais a remporté trois titres en 1937 à Chamonix. 

Emile Allais colle le mieux à l'énoncé : 
- Il est antérieur aux deux autres ("premières légendes du ski français")
- Il a remporté ses titres lors d'un mondial en France.

**Flag : 404CTF{emile-allais_chamonix}**

PS : ChatGPT est d'accord.

### Not on my watch (Facile)
On nous donne la photo "pocket_watch.png" : 
![Not on my watch](/OSINT/pocket_watch.jpg)

et l'intitulé suivant : 
> Vous êtes arbitre pour l'épreuve de ski de fond et vous accordez une attention particulière à tout ce qui touche au temps. Cependant, en vous réveillant le matin de la compétition, vous vous rendez compte que votre belle montre de poche s'est arrêtée pendant la nuit. Vous la démontez et vous rendez compte que le mécanisme a l'air endommagé. Sous le coup de la déception, vous entreprenez de trouver un nouveau mécanisme pour celle-ci. Vous vous renseignez donc sur le nombre de mécanismes qui ont été produits. 

Les éléments sur l'images : 
- Le mot "Waltham" correspond à une ville du Massachusetts (donc "Mass"). 
- L'inscription "A.W.W.CO" nous amène à l'American Waltham Watch Company (https://en.wikipedia.org/wiki/Waltham_Watch_Company). 
- On a aussi un numéro "15404141" (de série ?).
- On a également "15 JEWELS".

Sur [ce site](http://www.pocketwatchrepair.com/histories/waltham.html) on trouve une estimation de 35 millions de montres produites. Le flag 404CTF{35,000,000} ne passe pas. Normal, on n'a pas notre modèle précis.

D'après [ce site](https://www.cliniquehorlogere.ch/fr/archives-diverses/horlogerie-americaine/waltham-watch-co.html), le modèle date de [1907](https://www.cliniquehorlogere.ch/assets/thumbs/2356/1572630506_Waltham_15724762_a_1907.2948471b.jpg). Ou du moins c'est le mécanisme le plus ressemblant et dont le numéro de série est le plus proche (corrélé au site précédent qui situe aussi ce numéro de série à 1907). 

On trouve [ici](https://pocketwatchdatabase.com/guide/company/waltham/model/0s/model-1907/images) pas mal d'images dont notre modèle (voir [l'exemple le plus proche](https://pocketwatchdatabase.com/profile/Mobilaero/collection/view/4448)). Quelques éléments listés : 
- Manufacturer:	Waltham
- Grade:	No. 165
- Size:	0s
- Model:	1907
- Jewels:	17j
- Setting:	Pendant
- Finish:	Nickel
- Est. Date:	1907

"No. 165" semble être un nom de modèle. Quand on clique dessus on atterrit sur [cette page](https://pocketwatchdatabase.com/search/result/waltham/15481055/grade) où on trouve l'information : 197,100.

**Flag : 404CTF{197,100}**

## Web
### Vous êtes en RETARD (Intro)
Intitulé : 
> Vous voilà devant le stade pour voir le dernier match de votre équipe préférée, le Gorfou FC !
Malheureusement, vous êtes arrivé.e en retard et l'entrée est fermée... Mais pas de panique, il vous suffit de trouver un moyen pour quand même rentrer !

Le site : https://en-retard.challenges.404ctf.fr/

Dans le script inclus dans la page, on voit un event lié à une URL : 
```javascript
    setInterval(function() {
        var panneau = document.querySelector('.panneau');
        var barre = document.querySelector('.barre-en-fer');
        if (!panneau && barre) {
            barre.remove();
        }
    }, 100);

    document.querySelector('.entrer-dans-le-stade').addEventListener('click', function() {
        window.location.href = '/donnez-moi-mon-ticket-pitie';
    });

    window.onload = function() {
        var cookies = document.cookie.split('; ');
        var fraudeur = cookies.find(row => row.startsWith('fraude='));

        if (fraudeur && fraudeur.split('=')[1] === 'true') {
            var zoneTexte = document.querySelector('.zone-texte');
            zoneTexte.textContent = 'Vous avez essayé de frauder, mais le vigile vous a aperçu et vous a ramené à l\'entrée...';
            zoneTexte.style.display = 'block';
        }
    };
```

A la page https://en-retard.challenges.404ctf.fr/donnez-moi-mon-ticket-pitie on a aussi un script contenant un event lié à une URL : 
``` javascript
    var bouton = document.querySelector('.valider-billet');
    var billet = document.querySelector('.billet');
    window.validable = [];
    bouton.addEventListener('click', function() {
        if (window.validable.includes(billet.id)) {
            fetch('/set_cookie', {method: 'POST'}).then(function() {
                window.location.href = "/devant-le-match";
            });
        } else {
            alert('Billet non validé');
        }
    });
```

Mais en allant à https://en-retard.challenges.404ctf.fr/devant-le-match on retourne en page d'accueil avec le message : "Vous avez essayé de frauder, mais le vigile vous a aperçu et vous a ramené à l'entrée...".

On voit dans le CSS un commentaire disant que le panneau cache le bouton "Entrer de le stade". Je passe donc la div à hidden="True". On voit effectivement un bouton. Le clic mène à la page https://en-retard.challenges.404ctf.fr/donnez-moi-mon-ticket-pitie. On tourne en rond...

Je teste l'autre URL du script : /set_cookie. On retourne à la page d'accueil mais avec un cookie cette fois du nom de "fraude" avec valeur "true". Je change à "false". La veleur n'est pas retenue, je passe via Burp. 

Après un plombe à galérer, je teste juste la requête POST /set_cookie dans Rester et ça renvoie notamment : `set-cookie: allergies=404CTF{gluten-sucre-au-sucre}`. JPP.

**Flag : 404CTF{gluten-sucre-au-sucre}**

### Le match du siècle [1/2] (Intro)
Intitulé : 
> Vous voilà à quelques semaines du match tant attendu entre le Gorfou FC et l'AS Sealion.
Seulement, vous vous êtes pris au dernier moment pour acheter votre place. Trouvez un moyen d'obtenir un billet !

Le site : https://le-match-du-siecle.challenges.404ctf.fr/

On arrive sur une page avec différents billets achetables. Il faut se connecter pour acheter. Je crée un compte Test1234!/Test1234! avec lequel je me connecte. Je n'ai pas de crédit donc impossible d'acheter un billet dans les catégories restantes. La catégorie VIP est épuisée. Je regarde les requêtes qui transitent à l'aide de la console web et remarque à la connexion un POST contenant un JSON : 
```JSON
"token": "eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VybmFtZSI6IlRlc3QxMjM0ISIsImJpbGxldHMiOnsiVklQIjowLCJMYXRlcmFsZSI6MCwiRmFtaWxpYWxlIjowLCJFc3QiOjAsIk91ZXN0IjowLCJOb3JkIGV0IFN1ZCI6MH0sImlhdCI6MTcxMzcwNzc1OH0.EP_cvDWXWj2JK83NxqDXJ2kUbX-no7JjFcUlorg269R3U8a8jDU1oxfn5FJXkrImtPKuNGgbVhaU3FbC8_70VyNnI3dA_zLJ8bbhwYeP2GUOu1PZvDeIG7VFwjrkY_j95UdIW06BU7BJVSOMyELyb6CKTN3m6vMYo9JDqW76kALzjCXN_YPd2WvwgT_NzXwhQLeUfEhEDlg6-EkRlCqxi3R5RQUjTCvTdvFF1PPP4rF9rlWiiHPe6hNqV80S82TvaxXm0jWZGaULso118VM0JDi9WV9xRvu1FXHe7PnO2hRqRnm8GK-dHjmYZuBuGYGwW1NDWR1_gaNzf58uJQXqbw"
```

Ca ressemble furieusement à un JWT, go https://jwt.io/. 
Bingo : 
```JSON
{
  "username": "Test1234!",
  "billets": {
    "VIP": 0,
    "Laterale": 0,
    "Familiale": 0,
    "Est": 0,
    "Ouest": 0,
    "Nord et Sud": 0
  },
  "iat": 1713707758
```

Je remplace la partie centrale du JWT en encodant en Base64 la valeur "{"username":"Test1234!","billets":{"VIP":1,"Laterale":0,"Familiale":0,"Est":0,"Ouest":0,"Nord et Sud":0},"iat":1713707758}" c'est à dire avec 1 pour VIP plutôt que 0. 

Ca donne : 
```JSON
"token": "eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VybmFtZSI6IlRlc3QxMjM0ISIsImJpbGxldHMiOnsiVklQIjoxLCJMYXRlcmFsZSI6MCwiRmFtaWxpYWxlIjowLCJFc3QiOjAsIk91ZXN0IjowLCJOb3JkIGV0IFN1ZCI6MH0sImlhdCI6MTcxMzcwNzc1OH0.EP_cvDWXWj2JK83NxqDXJ2kUbX-no7JjFcUlorg269R3U8a8jDU1oxfn5FJXkrImtPKuNGgbVhaU3FbC8_70VyNnI3dA_zLJ8bbhwYeP2GUOu1PZvDeIG7VFwjrkY_j95UdIW06BU7BJVSOMyELyb6CKTN3m6vMYo9JDqW76kALzjCXN_YPd2WvwgT_NzXwhQLeUfEhEDlg6-EkRlCqxi3R5RQUjTCvTdvFF1PPP4rF9rlWiiHPe6hNqV80S82TvaxXm0jWZGaULso118VM0JDi9WV9xRvu1FXHe7PnO2hRqRnm8GK-dHjmYZuBuGYGwW1NDWR1_gaNzf58uJQXqbw"
```

Je place ça dans un cookie et roule. Quand je vais dans "Mes billets" j'ai un message : "Accès interdit aux hackers". Bon. 

Par contre il y a un 2e cookie avec une valeur "balance" à "0". Je la mets à "100" et je peux cliquer sur 40€ pour la tribune latérale. Mon solde est mis à jour (60€). Dans "Mes billets" j'ai bien un billet pour cette catégorie qui télécharge une image avec le flag.

**Flag : 404CTF{b5a77ed0fa6968b21df7fb137437fae1}**

### Exploit mag (facile) - Pas fini
Intitulé : 
> Alors que la compétition bat son plein, votre entraîneur vient à votre rencontre : "Hey ! Je ne sais pas si tu as vu, mais il parait qu'un magazine en ligne a publié des trucs *intéressants* sur la compétition. C'est un ami à moi qui m'a envoyé le lien." En allant jeter un œil, rien ne semble différencier ce magazine d'un autre site sportif aux titres racoleurs... Mais l'un des articles attire votre attention. Ce serait bien de pouvoir y accéder, au moins pour savoir ce qu'ont appris les athlètes qui l'ont lu. Mais pas question de payer, il doit bien exister un autre moyen...

Le site : https://exploit-mag.challenges.404ctf.fr/

Le site comporte trois pages : 
- Un accueil
- Une liste d'articles (/news)
- Une page de tarifs (/pricing) mais où le lien pour Premium (lecture illimitée) redirige vers /news. 

Un article attire immédiatement l'oeil : https://exploit-mag.challenges.404ctf.fr/news/dataleak-404-ctf/ mais protégé par un paywall.

![Article](/Web/Paywall.png)

Et un captcha infini bloque l'accès : 

![Captcha](/Web/Captcha.png)

Le code du captcha dans le HTML : 
```html
<label data-astro-cid-i5xthjb2>
    <input type="checkbox" onclick="this.setAttribute('disabled', 'disabled');" data-astro-cid-i5xthjb2>
        <span class="checkmark" data-astro-cid-i5xthjb2>
            <span data-astro-cid-i5xthjb2>&nbsp;</span>
        </span>
</label>
```

Je regarde via Wappalyzer les techno utilisées pour le site : 
- Astro 4.1.1, un framework JS. Voyons s'il existe des exploits pour ce truc. La version la plus récente est la 4.7, mais il n'y a pas l'air d'y avoir de gros problèmes connus pour la 4.1 (https://snyk.io/advisor/npm-package/astro).
- PHP, pas de version détectée.

Pas d'appel à un script douteux.
Pas de cookie à trifouiller non plus.
Pas d'entrée utilisateur.
Pas de fichier sourcé bizarrement.

Je ne sais pas trop où chercher... 

Je jette un coup d'oeil au `robots.txt` :
```txt
User-agent: Googlebot-news
Disallow:

User-agent: *
Disallow: /news/
```

Rien d'inspirant non plus.

En fait j'étais pas loin avec ce `robots.txt`.

**Solution expliquée par [HugoCls](https://github.com/HugoCls) dans son [write up](https://github.com/HugoCls/CTFs-WriteUps/blob/main/404CTF2024/Web/ExploitMag.md) :**
> Avec un peu de documentation sur internet, on apprend que certains sites laissent passer les bots crawlers de google pour obtenir un meilleur référencement, et il est possible d'usurper leur identité en utilisant leur User-Agent associé. [...] On reproduit la requête d'obtention de l'article `GET /news/dataleak-404-ctf/` en changeant l'User-Agent par celui d'un Google Bot : `Mozilla/5.0 (compatible; Googlebot/2.1; +http://www.google.com/bot.html)
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7`. Et on obtient directement l'article complet, et le flag. 

**Flag: 404CTF{p4yw4lL_bYpa55_1s_dAnG3r0us}.**

## Investigation numérique
### Le tir au logs (Intro)
Intitulé : 
> Il semblerait qu'une personne malveillante ait réussi à se connecter sur le site d'inscription d'une compétition de tir à l'arc.
Aidez-nous à investiguer sur cette attaque via le fichier de logs de notre serveur. Quel est l'URL complète qui a permis de se connecter de manière frauduleuse ?

On a un [fichier de logs](/Investigation_numérique/access.log).

En regardant les logs, l'IP 146.70.147.101 tente de façon très flagrante des injections SQL. L'attaquant semble y parvenir d'après la ligne 37 : 
> 146.70.147.101 - - [19/Feb/2024:19:28:44 -0500] "GET /index.php?username=admin%27%23&password=test HTTP/1.1" 302 784 "http://www.inscription_tir_arc.com/index.php?username=admin%22+AND+password+LIKE+%27a%25%27%23&password=test" "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:122.0) Gecko/20100101 Firefox/122.0"

On y voit en effet une redirection là où les autres essais retournaient un 200 (page login retournée).

Je teste : 
- 404CTF{http://www.inscription_tir_arc.com/index.php?username=admin%22+AND+password+LIKE+%27a%25%27%23&password=test}
- 404CTF{http://www.inscription_tir_arc.com/admin.php?username=admin%22+AND+password+LIKE+%27a%25%27%23&password=test}

Ca marche pas, ce qu'on veut c'est la requête de l'attaquant pour s'authentifier, pas la redirection !

**Flag : 404CTF{http://www.inscription_tir_arc.com/index.php?username=admin%27%23&password=test}**

### Darts bank (Moyen) - Pas fini
Avertissement : 
> Attention : ce challenge contient du code à portée malveillante. Bien que l'auteur se soit efforcé de le rendre relativement inoffensif, il convient de prendre les mesures d'isolation adéquates s'il devait être exécuté. L'organisation décline toute responsabilité en cas de dommages à votre système.

Intitulé : 
> Je me dirigeais vers l'épreuve de lancer de fléchettes quand j'ai fait une découverte horrifiante : on m'a dérobé ma fléchette porte-bonheur ! Pourtant, cette dernière était bien sécurisée grâce à ma banque à fléchettes, DartsBank, et cette dernière a toutes les protections qui s'imposent... Même le petit cadenas vert ! Je crois avoir remarqué des choses étranges sur le réseau, vous pouvez y jeter un œil ?

On nous fournit [un fichier de capture réseau](/Investigation_numérique/dart.pcapng) ouvrable avec Wireshark.

On remarque ligne 81 un paquet HTTP de 192.168.78.89 vers 192.168.78.31 qui contient une [charge visiblement malveillante en Powershell](/Investigation_numérique/Dart_bank_encoded_script.txt) en partie obfusquée en base 64. 
Je déobfusque et je trouve effectivement une [charge malveillante](/Investigation_numérique/Dart_bank_attack_script.txt_ps).
Ce dernier cherche visiblement à envoyer une requête via Chrome avec des données vers http://192.168.78.89/index.html. 

Accessoirement, dans la charge PS, on voit aussi une requête vers une URL, qu'on retrouve dans les échanges de paquets de la capture, dont on peut suivre la résolution DNS qui mène à une vidéo Youtube qui s'avère être, évidemment, un Rick roll. 

**Solution expliquée par [TechieNeurons](https://github.com/TechieNeurons) dans son [write-up](https://github.com/TechieNeurons/404CTF_2024_write_up/tree/main/forensics/darts_bank), ou par [hayb](https://github.com/haybb) (en plus condensé) dans son [write up](https://github.com/haybb/CTF-Write-Ups/tree/main/Darts%20Bank):**
*Le script malveillant utilise le navigateur Chrome avec une option `--ssl-key-log-file` permettant de stocker un certificat SSL dans un fichier. Il contient également un script (contenant notamment une longue variable en bytes) qui est placé dans le registre. Ce script permet d'utiliser la clef SSL préalablement stockée, de xor chaque byte de la longue variable, puis d'envoyer ce résultat à présent chiffré. Dans les communications TCP suivantes, on peut récupérer ces données chiffrées envoyées (trouvables dans Wireshark en isolant les requêtes HTTP avec `http.request.method == POST`) en neuf paquets, les xor dans l'autre sens avec la longue liste de bytes que l'on connait, et ainsi récupérer la clef SSL. En entrant cette clef SSL dans Wireshark, on peut maintenant déchiffrer la communication TLS. On trouve un fichier envoyé par le hostname `dartsbank.challenges.404ctf.fr` qui contient le flag.*

## Stéganographie
### L'absence (Intro)
Intitulé : 
> Hier, Francis n'était pas là à son épreuve de barres asymétriques, il nous a envoyé une lettre d'excuse. Malheureusement, la fin de sa lettre est illisible. Déchiffrez la fin de ses excuses.

On nous fournit une [lettre](/Stégano/lettre.txt).

On voit que certaines lettres en majuscules dans le texte forment le mot : GYMNASTIQUES.
Il signe du nom de Vigenere. 
On a donc probablement affaire à du chiffrement Vigenere avec la clef "GYMNASTIQUES".

Effectivement sur [Dcode](https://www.dcode.fr/chiffre-vigenere) on obtient : 
> En effet, j'ai du m'absenter car le drapeau de ma nation a ete dissimule par des gens qui voulaient faire perdre mon pays ! Mais apres une longue recherche, j'ai enfin pu le retrouver. Le voici : 404CTF{NeVolezPasLesDrapeauxSvp}

**Flag : 404CTF{NeVolezPasLesDrapeauxSvp}**

### Regarder en stéréo (Facile)
Intitulé : 
> Ça y est, c'est le grand jour ! Vous avez enfin atteint le niveau professionnel et, il faut faire vos preuves lors de cette première compétition. Le début de votre enchaînement gymnastique se déroule bien jusqu'à ce que votre plus grande peur se réalise. Une mauvaise réception en amenant une autre, vous ne contrôlez plus votre élan et tentez de vous rattraper tant bien que mal. Malheureusement, vous finissez par atterrir un peu trop loin en dehors des tapis. Voici la dernière vision que vous avez avant de heurter le sol, est-ce que quelque chose peut encore vous aider? 

On nous fournit [une image](/Stégano/chall_stega.png).

Vu la tronche de l'image c'est de l'autostéréoscopie qu'il faut utiliser. J'arrive effectivement à le voir mais lire des lettres dans un stéréogramme, c'est chaud. J'utilise donc [un outil](https://piellardj.github.io/stereogram-solver/) qui me donne ceci : ![stéréogramme](/Stégano/stereogram_solve.png)

Tu m'étonnes que j'arrivais pas à lire directement en 3D avec des lettres si fines...

**Flag : 404CTF{END_IS_NEAR}**

### La barre fixe (Facile mais seulement 22 flags =.=') - Pas fini
Intitulé : 
> C'est le grand moment, tous les yeux sont rivés sur vous. Vous vous apprêtez à commencer votre prestation sur l'épreuve de la barre fixe. Mais quelques instants avant de vous élancer, vous remarquez un détail intriguant. Certaines choses sont là... alors qu'elles ne devraient pas l'être... Un message peut être ?

On nous fournit [un fichier](/Stégano/chall.mov). 

C'est visiblement une vidéo mais d'une durée nulle. VLC l'ouvre mais il n'y a rien à lire.

Quand on l'exécute dans une console Linux cela donne : 
```
┌──(kali㉿kali)-[~/Downloads]
└─$ ./chall.mov       
UnMessagePasDuToutSuspect
```

Si on tente de transformer ce fichier en .zip, le format obtenu est illisible.

Si on tente de transformer ce fichier en .txt, on trouve une URL Youtube : https://www.youtube.com/watch?v=dQw4w9WgXcQ.
C'est un bon vieux RickRoll. Haha.

Avec IDA on peut analyser l'exécutable qui ne semble pas faire autre chose qu'afficher le message troll.

Analyse avec objdump : 
```
┌──(kali㉿kali)-[~/Downloads]
└─$ objdump -x chall.mov

chall.mov:     file format elf64-x86-64
chall.mov
architecture: i386:x86-64, flags 0x00000112:
EXEC_P, HAS_SYMS, D_PAGED
start address 0x0000000000401000

Program Header:
    LOAD off    0x0000000000000000 vaddr 0x0000000000400000 paddr 0x0000000000400000 align 2**12
         filesz 0x0000000000001000 memsz 0x0000000000001000 flags r--
    LOAD off    0x0000000000001000 vaddr 0x0000000000401000 paddr 0x0000000000401000 align 2**12
         filesz 0x000000000000012e memsz 0x000000000000012e flags r-x
    LOAD off    0x0000000000002000 vaddr 0x0000000000802000 paddr 0x0000000000802000 align 2**3
         filesz 0x0000000000001000 memsz 0x0000000000001000 flags r--

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         0000012e  0000000000401000  0000000000401000  00001000  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
  1 https://www.youtube.com/watch?v=dQw4w9WgXcQ 00001000  0000000000802000  0000000000802000  00002000  2**3
                  CONTENTS, READONLY
SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 empty.asm
0000000000401000 g       .text  0000000000000000 _start
0000000000402000 g       .text  0000000000000000 __bss_start
0000000000402000 g       .text  0000000000000000 _edata
0000000000402000 g       .text  0000000000000000 _end
```

Pas inspirant...

En fait il fallait s'y connaître en reverse.

**Solution expliquée par [Nathorn](https://github.com/Narthorn) dans son [write-up](https://github.com/Narthorn/ctf/tree/master/2024-04-20_404CTF-2024/06.%20steg/La%20Barre%20Fixe) :** 
*En observant de plus près les instructions qui permettent d'afficher le message troll, on voit que certaines sont [préfixées](https://wiki.osdev.org/X86-64_Instruction_Encoding#Legacy_Prefixes). Ces préfixes (il y en a quatre différents) n'ont pas vraiment de sens en x64 et sont toujours écrits dans le même ordre mais à différents endroits. Finalement, comme ces valeurs n'ont pas de sens, on peut se dire qu'elles sont remplaçables par des 1 et que les endroits où elles ne sont pas présentes sont assimilables à des 0. Ca donne des groupes de bits, qui vont deux par deux et s'avèrent être les deux moitiés inversées de caractères en ASCII. En convertissant ces caractères en ASCII, on retombe finalement sur le flag.

**FLAG : 404CTF{x86_64-iGnor3s-5TuFF}**

### Le grand écart (Moyen) - Pas fini
Intitulé : 
> En sortant de votre cours de gymnastique, vous tombez sur un étrange bouquin dans les vestiaires... À vous d'en trouver tous les secrets.

On nous fournit [un fichier](/Stégano/challenge.txt).

C'est visiblement une édition de Moby-Dick avec beaucoup de caractères problématiques. On peut trouver en ligne le [texte original](https://archive.org/details/mobydickorwhale01melvuoft/page/n7/mode/2up). On le trouve aussi avec la phrase chelou du début à l'identique [sur Gist](https://gist.github.com/StevenClontz/4445774). Visiblement c'est la transcription en texte d'un livre scanné, d'où les caractères problématiques. Mais pas que : il y a plus de caractères bizarres dans notre version. 

**Solution expliquée par [Blaireau](https://github.com/Blaireau) dans son [write-up](https://github.com/Blaireau/404CTF-2024/blob/main/steganographie/grand_ecart/writeup.md):**
> Certains caractères du fichier du challenge ont l'air d'être différent [de celui du dépôt Gist]. En analysant les différences entre les deux fichiers on se rend compte qu'à partir de la position 150, et tous les 30 caractères, les caractères sont différents. Cela dit les caractères récupérés de cette manière n'ont pas de cohérence, mais en faisant un XOR entre le caractère "original" et celui du fichier du challenge, on commence à obtenir le début du header d'un fichier PNG. [Génération de l'image à l'aide d'un script de son cru] Visiblement le challenge n'est pas fini... [...] En analysant le fichier avec **zSteg** on obtient le flag dans le canal suivant : `b1,rgba,lsb,xy .. text: "404CTF{you_spot_w3ll_the_differences}\n"`

**Une autre version de l'explication par [NozZy](https://nozyzy.github.io/) dans son [write-up](https://nozyzy.github.io/posts/grand-ecart/).**

**Flag : 404CTF{you_spot_w3ll_the_differences}**

### La chute (Moyen) - Pas fini
Intitulé : 
> Et l'athlète s'élance, sa performance est jusqu'à présent sans fautes ! Mais, que vient-il de se passer ? Il est tombé ! J'espère qu'il n'est pas gravement blessé, car rien n'est encore joué.  D'ailleurs, il essaie de nous dire quelque chose ! Mais qu'est-ce qu'il a bien pu vouloir dire ?

On nous fournit [un fichier](/Stégano/charabia.txt).

On arrive à apercevoir "404" et les accolades du flag dans le texte, mais pour le reste, aucune idée de quoi faire. Je teste avec une analyse fréquentielle des caractères et des substitutions simples, mais ça ne donne rien, d'autant qu'il y a 4 caractères entre "404" et l'accolade ouvrante, ce qui est étonnant puisqu'on attend "CTF" donc 3 caractères.

J'étais pas loin...

**Solution expliquée par [Blaireau](https://github.com/Blaireau) dans son [write-up](https://github.com/Blaireau/404CTF-2024/blob/main/steganographie/la_chute/writeup.md):**
> On suppose donc que le contenu du fichier est une simple substitution. En faisant une analyse fréquentielle on se rends compte que le caractère `л` est le plus présent. On pourrais supposer que c'est le `e`, lettre la plus fréquent en français, mais si on a à faire un texte avec des mots, on va supposer que ce caractère est un espace. La suite de caractère `[$λΣ`, doit encoder les lettres `C`, `T` et `F`, cela nous indique qu'un bigramme peut encoder une lettre. Il se trouve que le bigramme `[$` se trouve plusieurs fois dans le texte, alors que les deux autres bigrammes (`$λ` et `λΣ`) ne sont présents qu'une seule fois. On part donc sur `[$` encode `C`. On remplace toutes les occurences du bigramme dans le texte. L'analyse fréquentielle a aussi indiquée que `^` est le caractère le plus présent dans le texte, avec une valeur proche des occurences de la lettre `E`. On part donc sur : `^` encode `E`. En continuant ainsi, par recherche et remplacement, on reconstruit au fur et à mesure le texte [...] et on trouve le flag.

**Flag : 404CTF{CONTRE_LES_CHUTES_CHERCHEZ_LES_DRAPEAUX}**

## Rétro-ingénierie (reverse)
### Echauffement (Intro) - Pas fini
Intitulé : 
> Un bon échauffement permet non seulement d'éviter des blessures, mais aussi de conditionner son corps et son esprit au combat qui va suivre. Ce crackme devrait constituer un exercice adéquat.

On nous fournit [un fichier binaire](/Reverse/echauffement.bin). Je le décompile en ligne pour avoir un [premier aperçu](/Reverse/EchauffementDécompilé.c).

Dans ma Kali, quand je lance le binaire, je suis invitée à trouver un mot de passe dans un prompt. Si je tape un truc au pif, le programme se termine en disant que l'entrée n'est pas bonne : 
```
kali㉿kali)-[~/Downloads]
└─$ ./echauffement.bin 
Vous ne devinerez jamais le mot de passe secret ! Mais allez-y, essayez..
test
C'est bien ce que je pensais, vous ne connaissez pas le mot de passe..
```

J'ouvre le binaire avec IDA. Une fonction appelée `secret_func_dont_look_here` attire l'oeil et contient une variable appelée `secret_data`. 
On retrouve dans la pile la valeur de `secret_data` dont je copie la valeur dans [ce fichier](/Reverse/SecretData.txt). 

Une fois reformatée en héxadécimal ça donne : 

`68 5F 66 83 A4 87 F0 D1 B6 C1 BC C5 5C DD BE BD 56 C9 54 C9 D4 A9 50 CF D0 A5 CE 4B C8 BD 44 BD AA D9` 

ce qui retraduit en UTF-8 donne : 

`h_fÃ¤Ç°Ñ¶|ÅÝ¾ÝÉÉÉÏÅKÈ½DÝªÙ`

... Pas fou. 

Je tente avec ce qui donne de vrais caractères ou avec tous les caractères : 
```
┌──(kali㉿kali)-[~/Downloads]
└─$ ./echauffement.bin
Vous ne devinerez jamais le mot de passe secret ! Mais allez-y, essayez..
h_f\VTPKD
C'est bien ce que je pensais, vous ne connaissez pas le mot de passe..
                                                                                       
┌──(kali㉿kali)-[~/Downloads]
└─$ ./echauffement.bin
Vous ne devinerez jamais le mot de passe secret ! Mais allez-y, essayez..
h_fÃ¤Ç°Ñ¶|ÅÝ¾ÝÉÉÉÏÅKÈ½DÝªÙ
C'est bien ce que je pensais, vous ne connaissez pas le mot de passe..
```

Rien du tout.

**Solution expliquée par [ThaySan](https://ctf.thaysan.com/) dans son [write-up](https://ctf.thaysan.com/ctf-and-writeups/2024-or-404ctf/reverse/echauffement) :**
> La fonction `secret_func_dont_look_here` fait une vérification caractère par caractère sur notre mot de passe. L'équation pour chacun est `caractère * 2 - 1 = secret_caractère`. [...] Il suffit donc de récupérer les valeurs de 
`secret_data` et résoudre l'équation. On a donc : `password[i] = (secret_data[i] + 1) / 2`.