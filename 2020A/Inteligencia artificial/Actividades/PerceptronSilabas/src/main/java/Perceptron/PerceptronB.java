package Perceptron;

public class PerceptronB {

    String[] patron1 = {"B", "C", "D"};
    String[] patron2 = {"V", "R", "N"};
    String[] patron3 = {"P", "T", "S"};
    String[] patron4 = {"G", "Ñ", "Z"};
    String[] patron5 = {"L", "M", "F"};
    String[] patron6 = {"Y", "J", "H"};
    String[] vocales = {"a", "e", "i", "o", "u"};
    String silaba = "";

    public PerceptronB() {
    }

    public void BuscarLetra(String letra) {
        for (var x = 0; x < letra.length(); x++) {
            if (patron1[0].contains(letra) || patron1[1].contains(letra) || patron1[2].contains(letra)) {
                this.silaba = letra + vocales[0];
            }
            if (patron2[0].contains(letra) || patron2[1].contains(letra) || patron2[2].contains(letra)) {
                this.silaba = letra + vocales[1];
            }
            if (patron3[0].contains(letra) || patron3[1].contains(letra) || patron3[2].contains(letra)) {
                this.silaba = letra + vocales[2];
            }
            if (patron4[0].contains(letra) || patron4[1].contains(letra) || patron4[2].contains(letra)) {
                this.silaba = letra + vocales[3];
            }
            if (patron5[0].contains(letra) || patron5[1].contains(letra) || patron5[2].contains(letra)) {
                this.silaba = letra + vocales[4];
            }
            if (patron6[0].contains(letra) || patron6[1].contains(letra) || patron6[2].contains(letra)) {
                this.silaba = letra + vocales[0];
            }
        }
    }

    public String getSilaba() {
        return this.silaba;
    }
}
