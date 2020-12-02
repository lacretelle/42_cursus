var data_stage = null;
var id_stage = 0;
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

(function camera() {
  var width = 600;
  var height = 500;
  var streaming = false;
  var data = null;
  var video = document.querySelector('video');
  var canvas = document.getElementById('draw');
  var startpic = document.getElementById('startpic');
  var context = canvas.getContext('2d');
  var del_img = document.getElementById('delete');
  var record = document.getElementById('record');
  var btns = document.getElementsByClassName('btn_canvas');
  var aside = document.querySelector("aside");
  var titleImg = document.getElementById('title_img');
  var title = document.getElementById('title');

  if(navigator.mediaDevices && navigator.mediaDevices.getUserMedia) {
    navigator.mediaDevices.getUserMedia({ video: {width :width, height: height}, audio: false }).then(function(stream) {
        video.srcObject = stream;
        video.play();
    })
    .catch(function(err){});
  }
  video.addEventListener('canplay', function(ev){
  if (!streaming) {
    canvas.setAttribute('width', width);
    canvas.setAttribute('height', height);
    streaming = true;
  }
  }, false);

  startpic.addEventListener("click", function() {
    for (var i = 0; i < btns.length; i++) {
      btns[i].style.display = "inline-block";
    }
    titleImg.style.display = "inline-block";
	  context.drawImage(video, 0, 0, width, height);
    canvas.style.display = "block";
    data = canvas.toDataURL('image/png');
    video.pause();
    video.style.display = "none";
    startpic.style.display = "none";
  });

  record.addEventListener("click", function(e) {
    var ajax = new XMLHttpRequest();
    ajax.open("POST", "capture", true);
    ajax.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    ajax.onload = function(e) {
      if (e.srcElement.readyState == 4) {
        var stageImg = document.getElementsByClassName("slide_stage");
        canvas.style.display = "none";
        titleImg.style.display = "none";
        for (var i = 0; i < btns.length; i++) {
          btns[i].style.display = "none";
        }
        for (i = 0; i < stageImg.length; i++) {
          stageImg[i].style.display = "none";
        }
        video.style.display = "inline-block";
        video.play();
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
    title.value = "";
  });

  del_img.addEventListener("click", function(e) {
    video.play();
    canvas.style.display = "none";
    video.style.display = "inline-block";
    for (var i = 0; i < btns.length; i++) {
      btns[i].style.display = "none";
    }
  });

})()
