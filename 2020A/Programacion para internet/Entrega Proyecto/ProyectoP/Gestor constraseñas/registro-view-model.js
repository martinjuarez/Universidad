var observableModule = require("tns-core-modules/data/observable");

function RegistroViewModel() {
	var viewModel = observableModule.fromObject({
    onButtonTap: function () {
      console.log("Button was pressed");
    },

    textFieldValue: "",


	});

	return viewModel;
}

module.exports = RegistroViewModel;
