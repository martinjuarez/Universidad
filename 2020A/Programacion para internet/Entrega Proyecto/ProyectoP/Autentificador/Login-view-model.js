var observableModule = require("tns-core-modules/data/observable");

function LoginViewModel() {
	var viewModel = observableModule.fromObject({
    onButtonTap: function () {
      console.log("Button was pressed");
    },


	});

	return viewModel;
}

module.exports = LoginViewModel;
