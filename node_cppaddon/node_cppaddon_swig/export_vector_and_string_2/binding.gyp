{
    "targets": [
        {
            "target_name": "my_mod", 
            "sources": ["export.cpp", "export_wrap.cxx"],
            "cflags_cc!": ['-fno-exceptions', '-fno-rtti', '-fexceptions']
        }
    ]
}
