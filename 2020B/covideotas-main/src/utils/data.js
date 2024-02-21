export const generalInfo = {
  discarded: '1,045',
  suspects: '5',
  confirmed: '670',
};

export const users = [{
  email: 'eduardo@gmail.com',
  pass: '123'
}, {
  email: 'ismael@gmail.com',
  pass: '9876'
},{
  email: 'fojar83621@1981pc.com',
  pass: '123abc'
},{
  email: 'zancudo@gmail.com',
  pass: 'maizitos'
}];

export const locations = [{
  /*
  //Consti
  position: { lat: 20.726854, lng: -103.372247 },
  polygons: [{
    coords: [
      { lat: 20.725659, lng: -103.373896 },
      { lat: 20.728156, lng: -103.373479 },
      { lat: 20.727475, lng: -103.369261 },
      { lat: 20.725298, lng: -103.370205 },
      { lat: 20.725659, lng: -103.373896 },
    ],
    color: '#E47C84',
  }, {
    coords: [
      { lat: 20.728951, lng: -103.377571 },
      { lat: 20.731329, lng: -103.376938 },
      { lat: 20.730601, lng: -103.370436 },
      { lat: 20.727683, lng: -103.370865 },
      { lat: 20.728951, lng: -103.377571 },
    ],
    color: '#B4E1F6',
  }]
},{*/
  //Martin
position: { lat: 20.734095, lng: -103.401024 },
polygons: [{
  coords: [
    { lat: 20.735335, lng: -103.399674 },
    { lat: 20.733002, lng: -103.402246 },
    { lat: 20.732444, lng: -103.399018 },
    { lat: 20.734587, lng: -103.398598 },
    { lat: 20.735335, lng: -103.399674 },
  ],
  color: '#FFF633', //
}]
}];

export const cases = {
  confirmados: { today: '670', all: '109,060' },
  sospechosos: { today: 'Na', all: '17,204' },
  descartados: { today: '1045', all: '220,783' },
  defunciones: { today: '18', all: '4,621' },
}

/*,{
    //Martin
  position: { lat: 20.734095, lng: -103.401024 },
  polygons: [{
    coords: [
      { lat: 20.735335, lng: -103.399674 },
      { lat: 20.733002, lng: -103.402246 },
      { lat: 20.732444, lng: -103.399018 },
      { lat: 20.734587, lng: -103.398598 },
      { lat: 20.735335, lng: -103.399674 },
    ],
    color: '#E47C84',
  }]

}, {
    //Shiza
  position: { lat: 20.685580, lng: -103.347986 },
  polygons: [{
    coords: [
      { lat: 20.686701, lng: -103.349534 },
      { lat: 20.684391, lng: -103.349374 },
      { lat: 20.684572, lng: -103.346846 },
      { lat: 20.686850, lng: -103.346916 },
      { lat: 20.686701, lng: -103.349534 },
    ],
    color: '#E47C84',
  }]
},{
  //Isma
  position: { lat: 20.762481, lng: -103.441375 },
  polygons: [{
    coords: [
      { lat: 20.761556, lng: -103.440560 },
      { lat: 20.762618, lng: -103.443400 },
      { lat: 20.764381, lng: -103.443067 },
      { lat: 20.763213, lng: -103.440073 },
      { lat: 20.761556, lng: -103.440560 },
    ],
    color: '#FFF633',
  }]
}*/