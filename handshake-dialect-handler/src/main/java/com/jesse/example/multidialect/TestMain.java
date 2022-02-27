package com.jesse.example.multidialect;

import java.util.Objects;
import java.util.stream.Stream;

public class TestMain {
    public static void main(String[] args) {
        //mock handshake result
        HandshakeResult result = new HandshakeResult(false, "A");
        Dialect dialect = Stream.of(new ADialectHandshakeHandler().check(), new BDialectHandshakeHandler().check())
                .map(x -> x.apply(result))
                .filter(Objects::nonNull)
                .findFirst()
                .get();
        if (dialect != null) {
            System.out.println(dialect.getClass().getName());
        }
    }
}
