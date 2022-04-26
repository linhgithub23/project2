
    Path path1;
    path1.addPoint(0, 1);
    path1.addPoint(1, 3);
    cout << path1.toString() << endl;

    // Character: simple test
    Character chWatson("Watson");
    cout << chWatson.toString() << endl;
    chWatson.moveToPoint(2, 7);
    cout << chWatson.toString() << endl;

    return 0;
}