var message = document.getElementById('message');
var pwd = this.location.origin;
var pathname = this.location.pathname.split('/');

function like(n) {
  var ajax = new XMLHttpRequest();
  var logo = document.getElementById(n);
  var heart = document.getElementById('heart'+n);
  ajax.open("POST", pwd+"/"+pathname[1]+"/home/manageLike", true);
  ajax.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
  ajax.onload = function(e) {
    if (e.srcElement.readyState == 4) {
      if (this.responseText != "0") {
        var p = this.responseText;
        heart.innerHTML = " "+p;
      } else {
        heart.innerHTML = "";
      }
    }
  }
  if (logo.style.color == "red") {
    logo.style.color = 'rgb(212,175,55)';
    ajax.send('id_img='+n+'&action=delete&nblike='+heart.innerHTML);
  } else {
    logo.style.color = "red";
    ajax.send('id_img='+n+'&action=add&nblike='+heart.innerHTML);
  }
}

function displayPost(n) {
  var disPosts = document.getElementById('displayCom_'+n);
  if (disPosts.style.display == "none") {
    disPosts.style.display = "inline-block";
  } else {
    disPosts.style.display = "none";
  }
}

function post(n) {
  var post = document.getElementById('post_'+n);
  var com = document.getElementById('com_'+n);
  if (post.style.display == "none") {
    post.style.display = "inline-block";
  } else {
    post.style.display = "none";
    com.value = "";
  }
}
function addPost(n) {
  var com = document.getElementById('com_'+n);
  var comments = document.getElementById('comments'+n);
  var ajax = new XMLHttpRequest();

  ajax.open("POST", pwd+"/"+pathname[1]+"/home/addPost", true);
  ajax.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
  ajax.onload = function(e) {
    if (e.srcElement.readyState == 4) {
      message.style.display = "flex";
      message.className = "success";
      var p = document.createElement("p");
      p.innerHTML = 'Votre commentaire a bien été ajouté !';
      message.append(p);
      var post = document.getElementById('post_'+n);
      post.style.display = "none";
      if (this.responseText != "0") {
        var l = this.responseText;
        comments.innerHTML = " "+l;
      } else {
        comments.innerHTML = "";
      }
    }
  }
  ajax.send('post='+com.value+'&id_img='+n+'&nbpost='+comments.innerHTML);
  com.value = "";
}
