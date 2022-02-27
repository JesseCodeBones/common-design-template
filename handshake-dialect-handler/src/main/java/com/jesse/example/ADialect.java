package com.jesse.example;

public class ADialect implements Dialect{
    @Override
    public void handleCommand(String command) {
        System.out.println("A is handling");
    }
}
