import { registerPlugin } from '@pexip/plugin-api'

;(async () => {
  // Resolve paths relative to this bundle (like whiteboard/betterchat)
  const assetsBase = new URL('.', import.meta.url) // .../dist/assets/
  const distBase = new URL('..', assetsBase).toString() // .../dist/

  const getDoomHtml = (): string => new URL('doom-crt.html', distBase).toString()

  try {
    console.info('[DOOM] Initializing via @pexip/plugin-api - VERSION 1.0.0 (No Sharing)')
    console.info('[DOOM] Using custom DOOM build')
    const plugin = await registerPlugin({ id: 'doom', version: 1 })

    const icon = {
      custom: {
        main: '<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512"><rect width="512" height="512" rx="64" fill="rgb(43, 64, 84)"/></svg>',
        hover: '<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512"><rect width="512" height="512" rx="64" fill="white"/></svg>'
      }
    }

    const button = await plugin.ui.addButton({ position: 'toolbar', tooltip: 'Play DOOM', icon })
    console.info('[DOOM] Toolbar button registered (plugin-api)')

    const openOverlay = (targetUrl: string) => {
      try {
        console.log('[DOOM] Creating overlay with URL:', targetUrl)
        const d = parent?.document || document
        const existing = d.getElementById('doom-overlay')
        if (existing) existing.remove()
        const overlay = d.createElement('div')
        overlay.id = 'doom-overlay'
        overlay.style.cssText = 'position:fixed;inset:0;z-index:20000;background:rgba(0,0,0,0.6);display:flex;align-items:center;justify-content:center;'

        const frameWrap = d.createElement('div')
        frameWrap.style.cssText = 'position:relative;width:960px;height:720px;box-shadow:0 8px 24px rgba(0,0,0,0.5);border-radius:8px;overflow:hidden;background:#000;'

        const close = d.createElement('button')
        close.textContent = '✕'
        close.style.cssText = 'position:absolute;top:8px;right:8px;z-index:1;padding:6px 10px;border:none;border-radius:4px;background:#2b4054;color:#fff;cursor:pointer'
        close.addEventListener('click', () => {
          overlay.remove()
        })

        const iframe = d.createElement('iframe')
        iframe.id = 'doom-frame'
        iframe.src = targetUrl
        iframe.style.cssText = 'width:100%;height:100%;border:0;'
        iframe.sandbox.add('allow-scripts')
        iframe.sandbox.add('allow-same-origin')
        iframe.sandbox.add('allow-pointer-lock')
        iframe.sandbox.add('allow-popups')

        // Add load event listener to debug iframe loading
        iframe.addEventListener('load', () => {
          console.log('[DOOM] Iframe loaded, checking for canvas...')
          setTimeout(() => {
            try {
              const iframeDoc = iframe.contentDocument || iframe.contentWindow?.document
              if (iframeDoc) {
                const canvases = iframeDoc.querySelectorAll('canvas')
                console.log('[DOOM] Canvas count in iframe:', canvases.length)
                canvases.forEach((c, i) => {
                  console.log(`[DOOM] Iframe canvas ${i}: id="${c.id}", width=${c.width}, height=${c.height}`)
                })
              } else {
                console.log('[DOOM] Cannot access iframe document (CORS)')
              }
            } catch (error) {
              console.log('[DOOM] Error accessing iframe content:', error)
            }
          }, 1000)
        })

        frameWrap.appendChild(close)
        frameWrap.appendChild(iframe)
        overlay.appendChild(frameWrap)
        d.body.appendChild(overlay)
        console.log('[DOOM] Overlay created and iframe added')
      } catch (e) {
        console.error('[DOOM] Failed to open overlay, falling back to new tab', e)
        window.open(targetUrl, '_blank')
      }
    }

    button.onClick.add(async () => {
      const url = getDoomHtml()
      console.log('[DOOM] Opening DOOM at URL:', url)
      try {
        // Prefer native panel from plugin API
        // @ts-ignore - openPanel may be available in current API version
        if (plugin.ui.openPanel) {
          console.log('[DOOM] Using openPanel API')
          // @ts-ignore
          await plugin.ui.openPanel({ url, width: 960, height: 720 })
          console.log('[DOOM] Panel opened')
          return
        }
      } catch (error) {
        console.log('[DOOM] openPanel failed:', error)
      }
      console.log('[DOOM] Using overlay fallback')
      openOverlay(url)
    })

    // Plugin initialized successfully
  } catch (error) {
    console.error('[DOOM] Failed to initialize plugin:', error)
  }
})()

