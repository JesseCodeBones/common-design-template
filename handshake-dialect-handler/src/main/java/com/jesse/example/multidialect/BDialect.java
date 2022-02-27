package com.jesse.example.multidialect;

public class BDialect implements Dialect{
    @Override
    public void handleCommand(String command) {
        System.out.println("B is handling");
    }
}
