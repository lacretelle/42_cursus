function displayInfo() {
  var account = document.getElementsByClassName("account");
  var info = document.getElementsByClassName("stage")[0];
  for (var i = 0; i < account.length; i++) {
    account[i].style.display = "flex";
  }
  info.style.display = "none";
}

function hideInfo() {
  var account = document.getElementsByClassName("account");
  var info = document.getElementsByClassName("stage")[0];
  for (var i = 0; i < account.length; i++) {
    account[i].style.display = "none";
  }
  info.style.display = "block";
}

(function() {
  var notif = document.querySelector('input[type=checkbox]');
  var inputNotif = document.querySelector('input[name=notif]');
   notif.addEventListener("click", function(){
     if (inputNotif.value == 0) {
       inputNotif.value = 1;
     } else {
       inputNotif.value = 0;
     }
   });
})
()
