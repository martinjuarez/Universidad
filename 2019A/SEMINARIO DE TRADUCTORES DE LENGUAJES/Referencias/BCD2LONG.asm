        ORG     0X0100
        xor     ax,ax
        lea     di,n_bcd
        mov     al,[di]
        mov     bx,10000
        mul     bx
        mov     [rh],dx
        mov     [rl],ax

        inc     di
        xor     ax,ax
        mov     al,[di]
        mov     bx,1000
        mul     bx
        add     [rl],ax
        adc     [rh],dx

        inc     di
        xor     ax,ax
        mov     al,[di]
        mov     bx,100
        mul     bx
        add     [rl],ax
        adc     [rh],dx

        inc     di
        xor     ax,ax
        mov     al,[di]
        mov     bx,10
        mul     bx
        add     [rl],ax
        adc     [rh],dx

        inc     di
        xor     ax,ax
        mov     al,[di]
        add     [rl],ax
        adc     [rh],dx
        ret
     
        
n_bcd   db      0,0,0,0,0
rh      dw      0
rl      dw      0        