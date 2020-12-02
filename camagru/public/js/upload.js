var data_stage = null;
var id_stage = 0;
var imgElement = document.getElementById('imgPrev');
var check = document.getElementById('check');
var upload = document.getElementsByClassName("upload")[0];
var message = document.getElementById('message');

function currentDiv(n) {
  var i;
  var slideIndex = n;
  var hide_stage = document.getElementById('hide_stage');
  var ctx = hide_stage.getContext('2d');
  var stage = document.getElementsByClassName("slide_stage");
  var mini = document.getElementsByClassName("demo");
  var startpic = document.querySelector("#startpic");
  if (n > stage.length)
    slideIndex = 1;
  if (n < 1)
    slideIndex = stage.length;
  for (i = 0; i < stage.length; i++) {
    stage[i].style.display = "none";
  }
  stage[slideIndex-1].style.display = "inline-block";
  hide_stage.setAttribute('width', 600);
  hide_stage.setAttribute('height', 500);
  ctx.clearRect(0, 0, 600, 500);
  ctx.drawImage(stage[slideIndex-1], 70, 100, 450, 350);
  startpic.style.display = "block";
  data_stage = hide_stage.toDataURL('image/png');
  id_stage = n;
}

function validate_fileupload(fileName) {
  var allowed_extensions = new Array("jpg","png","gif","jpeg");
  var file_extension = fileName.split('.').pop().toLowerCase();
  for(var i = 0; i <= allowed_extensions.length; i++) {
    if(allowed_extensions[i]==file_extension) {
      return true;
    }
  }
  return false;
}

function previewFile(e) {
  var reader = new FileReader();
  var file = document.querySelector('input[type=file]').files[0];
  var prev = document.getElementById('prev');

  if (validate_fileupload(e) == true) {
    reader.addEventListener("load", function() {
      prev.style.display = "flex";
      imgElement.setAttribute("width", '100%');
      imgElement.setAttribute("height", 'auto');
      imgElement.alt = file.name;
      imgElement.src = reader.result;
      prev.appendChild(imgElement);
      check.style.display = "inline-block";
    }, false);
    if (file) {
      reader.readAsDataURL(file);
    }
  } else {
    message.className = "success";
    message.style.display = "flex";
  }
}

function drawCanvas(image) {
  var width = 600;
  var height = 500;
  var data = null;
  var canvas = document.getElementById('draw');
  var context = canvas.getContext('2d');
  var aside = document.querySelector("aside");
  canvas.setAttribute('width', width);
  canvas.setAttribute('height', height);
  context.drawImage(image, 0, 0, width, height);
  canvas.style.display = "block";
  data = canvas.toDataURL('image/png');
  return (data);
}

(function() {
  var btns = document.getElementsByClassName('btn_canvas');
  var del_img = document.getElementById('delete');
  var record = document.getElementById('record');
  var data = null;
  var canvas = document.getElementById('draw');
  var titleImg = document.getElementById('title_img');
  var title = document.getElementById('title');
  var stageImg = document.getElementsByClassName("slide_stage");

  check.addEventListener("click", function() {
    var stage = document.getElementsByClassName('stage')[0];
    stage.style.display = "inline-block";
    upload.style.display = "none";
    data = drawCanvas(imgElement);
  });

  startpic.addEventListener("click", function() {
    for (var i = 0; i < btns.length; i++) {
      btns[i].style.display = "inline-block";
    }
    titleImg.style.display = "inline-block";
    if (document.getElementById('title_img').className = "hide_title")
      document.getElementById('title_img').className = "title_img";
    startpic.style.display = "none";
  });
  record.addEventListener("click", function(e) {
    var ajax = new XMLHttpRequest();
    ajax.open("POST", "capture", true);
    ajax.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    ajax.onload = function(e) {
      if (e.srcElement.readyState == 4) {
        var stage = document.getElementsByClassName('stage')[0];
        var canvas = document.getElementById('draw');
        var prev = document.getElementById('prev');

        for (i = 0; i < stageImg.length; i++) {
          stageImg[i].style.display = "none";
        }
        for (var i = 0; i < btns.length; i++) {
          btns[i].style.display = "none";
        }
        stage.style.display = "none";
        canvas.style.display = "none";
        titleImg.style.display = "none";
        prev.style.display = "none";
        check.style.display = "none";
        upload.style.display = "inline-block";
        message.style.display = "flex";
        message.className = "success";
        var h = document.getElementsByClassName('img_aside')[0];
        var div = document.createElement("div");
        var div2 = document.createElement("div");
        div.setAttribute("class", "polaroid");
        div2.setAttribute("class", "letter");
        var x = document.createElement("IMG");
        x.setAttribute("src", "../"+this.responseText);
        x.setAttribute("width", "100%");
        var letter = document.createElement("p");
        letter.innerHTML = 'Photo enregistrée !';
        div2.append(letter);
        div.append(x);
        div.append(div2);
        h.prepend(div);
        var p = document.createElement("p");
        p.innerHTML = 'Votre montage a bien été enregistrée !';
        message.append(p);
      }
    }
    if (title.value == 0) {
      ajax.send('data='+encodeURIComponent(data)+'&stage='+encodeURIComponent(data_stage)+'&id_stage='+id_stage);
    }
    else {
      ajax.send('data='+encodeURIComponent(data)+'&stage='+encodeURIComponent(data_stage)+'&id_stage='+id_stage+'&title_img='+title.value);
    }
  });

  del_img.addEventListener("click", function(e) {
    for (var i = 0; i < btns.length; i++) {
      btns[i].style.display = "none";
    }
    startpic.style.display = "block";
  });
})()
