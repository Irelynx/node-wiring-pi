{
  'targets': [
    {
      'target_name': 'wiringPi',
      'sources': [
        'src/bindings.cc'
      ],
      'libraries': [
        '-lwiringPi'
      ],
      'cflags': [
        '-Wall',
        '-std=c++11'
      ]
    }
  ]
}