var HomeViewModel = require("./home-view-model");
var homeViewModel = new HomeViewModel();
var frames = require("ui/frame");
var frameModule = require("tns-core-modules/ui/frame");
var dialogs = require("tns-core-modules/ui/dialogs");
const model = require('./model');

function pageLoaded(args) {
  var page = args.object;
  page.bindingContext = homeViewModel;
}

exports.registro = function (args) {
  var navegation = {
    moduleName: "home/registro-page",
    transition: {
      name: "slideBottom"
    }
  };
  frames.topmost().navigate(navegation);
}

exports.iniciarSesion = function (args) {
  const pageSesion = args.object.page;
  const correoUsuario = pageSesion.getViewById("Correo");
  const contrasenaUsuario = pageSesion.getViewById("Contraseña");
  var xhttp = new XMLHttpRequest();
  if (correoUsuario.text == "" || contrasenaUsuario.text == "") {
    dialogs.alert({
      title: "Aviso!", message: "Hay campos vacios, debe llenar todos los campos",
      okButtonText: "ok"
    })
  } else {
    xhttp.onreadystatechange = function () {
      if (this.readyState == 4 && this.status == 200) {
        const response = xhttp.responseText;
        const [estatus, id] = response.split("|");
        if (estatus == "Login correcto") {
          model.userName = correoUsuario.text;
          model.password = contrasenaUsuario.text;
          model.id = id;
          correoUsuario.text = "";
          contrasenaUsuario.text = "";
          var navegation = {
            moduleName: "home/Autentificador-page",
            transition: {
              name: "slideBottom"
            }
          };
          frames.topmost().navigate(navegation);
        } else if (estatus == "Login incorrecto") {
          dialogs.alert({
            title: "¡Aviso!",
            message: "No se encontro el usuario",
            okButtonText: "Ok"
          })
        }
      }
    };
    xhttp.open("POST", "https://mywebfome.000webhostapp.com/Login.php", true);
    xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    xhttp.send("CorreoElectronico=" + correoUsuario.text + "&Contraseña=" + contrasenaUsuario.text);
  }
}

exports.pageLoaded = pageLoaded;