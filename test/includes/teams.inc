<?php

function _get_teams() {
    return  [
          'real-madrid' => [
                                'name' => 'Real Madrid',
                                'logo' => 'rm/rm.jpg',
                                'members' => [
                                                [
                                                    'name' => 'Cristiano Ronaldo',
                                                    'wins' => 312,
                                                    'picture' => 'rm/cristiano_ronaldo.jpg',
                                                    'number' => 7,
                                                    'salary' => 20000000000
                                                ],
                                                [
                                                    'name' => 'Gareth Bale',
                                                    'wins' => 56,
                                                    'picture' => 'rm/gareth_bale.jpg',
                                                    'number' => 11,
                                                    'salary' => 15000000000
                                                ],
                                                [
                                                    'name' => 'Karim Benzema',
                                                    'wins' => 250,
                                                    'picture' => 'rm/karim_benzema.jpg',
                                                    'number' => 9,
                                                    'salary' => 15000000000
                                                ]
                                              ],
                            ],
          'fc-bihor' => [
                                'name' => 'FC Bihor',
                                'logo' => 'bh/bh.png',
                                'members' => [
                                                [
                                                    'name' => 'Mutu',
                                                    'wins' => 110000,
                                                    'picture' => 'bh/mutu.jpg',
                                                    'number' =>17,
                                                    'salary' => 20000000000
                                                ],
                                                [
                                                    'name' => 'Gigi Becali',
                                                    'wins' => 3221,
                                                    'picture' => 'bh/gigi.jpg',
                                                    'number' => 11,
                                                    'salary' => 15000000000
                                                ],
                                                [
                                                    'name' => 'Barabas Vilmos Bela',
                                                    'wins' => 100000,
                                                    'picture' => 'bh/vili.jpg',
                                                    'number' => 9,
                                                    'salary' => 32441312221321
                                                ]
                                              ],
                            ],
          ];
}

