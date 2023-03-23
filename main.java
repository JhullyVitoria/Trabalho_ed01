package com.example.ex01;

public class main
{
    public static void main(String args[]){

        figurinhas jg_1 = new figurinhas();
        figurinhas jg_2 = new figurinhas();
        figurinhas jg_3 = new figurinhas();

        jg_1.nome = "Casemiro";
        jg_1.nascimento = "23.02.1991";
        jg_1.altura = 1.85f;
        jg_1.peso = 84.00f;
        jg_1.posicao = "Meio-campista";
        jg_1.pais = "Brasil";

        jg_2.nome = "Danilo";
        jg_2.nascimento = "15.07.1991";
        jg_2.altura = 1.84f;
        jg_2.peso = 74.00f;
        jg_2.posicao = "Lateral";
        jg_2.pais = "Brasil";

        jg_3.nome = "Ederson";
        jg_3.nascimento = "17.08.1993";
        jg_3.altura = 1.88f;
        jg_3.peso = 89.00f;
        jg_3.posicao = "Goleiro";
        jg_3.pais = "Brasil";

        System.out.println("Nome:" + jg_1.nome);
        System.out.println("Nascimento:" + jg_1.nascimento);
        System.out.println("Altura:" + jg_1.altura);
        System.out.println("Peso:" + jg_1.peso);
        System.out.println("Posição:" + jg_1.posicao);
        System.out.println("País:" + jg_1.pais);

        System.out.println("");

        System.out.println("Nome:" + jg_2.nome);
        System.out.println("Nascimento:" + jg_2.nascimento);
        System.out.println("Altura:" + jg_2.altura);
        System.out.println("Peso:" + jg_2.peso);
        System.out.println("Posição:" + jg_2.posicao);
        System.out.println("País:" + jg_2.pais);

        System.out.println("");

        System.out.println("Nome:" + jg_3.nome);
        System.out.println("Nascimento:" + jg_3.nascimento);
        System.out.println("Altura:" + jg_3.altura);
        System.out.println("Peso:" + jg_3.peso);
        System.out.println("Posição:" + jg_3.posicao);
        System.out.println("País:" + jg_3.pais);


    }
}
