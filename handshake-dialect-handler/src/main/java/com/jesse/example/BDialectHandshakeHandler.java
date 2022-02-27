package com.jesse.example;

import java.util.function.Function;

public class BDialectHandshakeHandler {

    Function<HandshakeResult, Dialect> check(){
        return result -> {
            if (result.hasError) {
                return null;
            } else {
                if (result.flag.equals("A")) {
                    return new ADialect();
                } else {
                    return null;
                }
            }
        };
    }
}
