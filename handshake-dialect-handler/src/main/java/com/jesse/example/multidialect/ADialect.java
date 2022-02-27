package com.jesse.example.multidialect;

public class ADialect implements Dialect{
    @Override
    public void handleCommand(String command) {
        System.out.println("A is handling");
    }
}
