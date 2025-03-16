//https://neps.academy/br/exercise/278

import java.util.*;

class DisponibilidadeCarta {
    public boolean alice;
    public boolean beatriz;

    public DisponibilidadeCarta(Boolean alice, Boolean beatriz) {
        this.alice = alice;
        this.beatriz = beatriz;
    }

    public void setBeatriz(boolean beatriz) {
        this.beatriz = beatriz;
    }
}



public class Main {

    final static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int qtdCartasA;
        int qtdCartasB;


        Map<Integer, DisponibilidadeCarta> cartas = new HashMap<>();
        Set<Integer> subConjuntoAlice = new HashSet<>();
        Set<Integer> subConjuntoBeatriz = new HashSet<>();


        //Receber a quantidade de cartas da Alice e de Beatriz
        qtdCartasA = scanner.nextInt();
        qtdCartasB = scanner.nextInt();



        //Receber as cartas da Alice assumindo que Beatriz não as possui
        int cartaA_;
        for (int i = 0; i < qtdCartasA; i++){
            cartaA_ = (scanner.nextInt());

            if (!cartas.containsKey(cartaA_)) //Verificar se é uma carta repetida
                cartas.put(cartaA_, new DisponibilidadeCarta(true, false));
        }

        //Receber as cartas da Beatriz levando em conta que a carta pode ser uma que a Alice já possui
        int cartaB_;
        for (int i = 0; i < qtdCartasB; i++) {
            cartaB_ = scanner.nextInt();

            if (cartas.containsKey(cartaB_)) //Pode ser uma carta repetida da Beatriz ou uma carta da Alice
                cartas.get(cartaB_).setBeatriz(true);
            else
                cartas.put(cartaB_, new DisponibilidadeCarta(false, true));
        }
        scanner.close();



        //Calcular os subconjuntos
        cartas.forEach((carta_, possuiCarta_) -> {
            if (possuiCarta_.alice && !possuiCarta_.beatriz) {
                subConjuntoAlice.add(carta_);
            }
            else if (!possuiCarta_.alice && possuiCarta_.beatriz) {
                subConjuntoBeatriz.add(carta_);
            }
        });



        //Imprimir a quantidade de trocas possíveis, que é o menor subconjunto
        System.out.println(Math.min(subConjuntoAlice.size(), subConjuntoBeatriz.size()));
    }
}