import { reactive } from "vue"

const STORAGE_KEY = "galaxy-language"

export const LANGUAGE_OPTIONS = [
  { value: "en", label: "English" },
  { value: "es", label: "Spanish" },
  { value: "fr", label: "French" },
  { value: "ko", label: "Korean" },
  { value: "zh-CHS", label: "Chinese" },
]

const SUPPORTED_CODES = new Set(LANGUAGE_OPTIONS.map((option) => option.value))

// Galaxy deliberately keeps English as the fallback. This lets new server-side
// labels ship safely before they have been added to every translation below.
const TRANSLATIONS = {
  es: {
    English: "Inglés", Spanish: "Español", French: "Francés", Korean: "Coreano", Chinese: "Chino",
    Home: "Inicio", Toggles: "Interruptores", Tools: "Herramientas", Recordings: "Grabaciones",
    Bluetooth: "Bluetooth", "Cameras & Monitoring": "Cámaras y monitoreo", Galaxy: "Galaxy",
    "Logs & Diagnostics": "Registros y diagnósticos", "Model Manager": "Administrador de modelos",
    "Navigation & Maps": "Navegación y mapas", "System Tools": "Herramientas del sistema",
    "Model Laboratory": "Laboratorio de modelos", Plots: "Gráficas", "Testing Ground": "Área de pruebas",
    "Theme Maker": "Creador de temas", "Tuning, Plots & Testing": "Ajustes, gráficas y pruebas",
    "Vehicle Controls": "Controles del vehículo", Main: "Principal", Offline: "Sin conexión", Parked: "Estacionado",
    Back: "Atrás", Menu: "Menú", "Galaxy home": "Inicio de Galaxy", "Search toggles...": "Buscar interruptores...",
    "Search toggles": "Buscar interruptores", "Clear search": "Borrar búsqueda", "Dark mode": "Modo oscuro",
    "Light mode": "Modo claro", "Switch to dark mode": "Cambiar a modo oscuro", "Switch to light mode": "Cambiar a modo claro",
    Settings: "Configuración", Language: "Idioma", "Select language": "Seleccionar idioma", Advanced: "Avanzado",
    "result(s)": "resultado(s)",
    "Galaxy uses English when no language is selected.": "Galaxy usa inglés si no se selecciona un idioma.",
    "Language updated.": "Idioma actualizado.", "Unable to save language.": "No se pudo guardar el idioma.",
    "Loading configuration...": "Cargando configuración...", "No settings available.": "No hay ajustes disponibles.",
    "No settings in this section.": "No hay ajustes en esta sección.", "Locked:": "Bloqueado:", "Step:": "Paso:",
    "This setting can only be changed while parked.": "Este ajuste solo se puede cambiar mientras el vehículo está estacionado.",
    Default: "Predeterminado", "Loading...": "Cargando...", "No options available": "No hay opciones disponibles",
    "Working...": "Procesando...", Run: "Ejecutar", Manage: "Administrar", Close: "Cerrar", Stock: "Original",
  },
  fr: {
    English: "Anglais", Spanish: "Espagnol", French: "Français", Korean: "Coréen", Chinese: "Chinois",
    Home: "Accueil", Toggles: "Options", Tools: "Outils", Recordings: "Enregistrements",
    Bluetooth: "Bluetooth", "Cameras & Monitoring": "Caméras et surveillance", Galaxy: "Galaxy",
    "Logs & Diagnostics": "Journaux et diagnostics", "Model Manager": "Gestionnaire de modèles",
    "Navigation & Maps": "Navigation et cartes", "System Tools": "Outils système",
    "Model Laboratory": "Laboratoire de modèles", Plots: "Graphiques", "Testing Ground": "Zone de test",
    "Theme Maker": "Créateur de thèmes", "Tuning, Plots & Testing": "Réglages, graphiques et tests",
    "Vehicle Controls": "Commandes du véhicule", Main: "Principal", Offline: "Hors ligne", Parked: "Stationné",
    Back: "Retour", Menu: "Menu", "Galaxy home": "Accueil Galaxy", "Search toggles...": "Rechercher des options...",
    "Search toggles": "Rechercher des options", "Clear search": "Effacer la recherche", "Dark mode": "Mode sombre",
    "Light mode": "Mode clair", "Switch to dark mode": "Passer au mode sombre", "Switch to light mode": "Passer au mode clair",
    Settings: "Paramètres", Language: "Langue", "Select language": "Choisir la langue", Advanced: "Avancé",
    "result(s)": "résultat(s)",
    "Galaxy uses English when no language is selected.": "Galaxy utilise l’anglais si aucune langue n’est sélectionnée.",
    "Language updated.": "Langue mise à jour.", "Unable to save language.": "Impossible d’enregistrer la langue.",
    "Loading configuration...": "Chargement de la configuration...", "No settings available.": "Aucun réglage disponible.",
    "No settings in this section.": "Aucun réglage dans cette section.", "Locked:": "Verrouillé :", "Step:": "Pas :",
    "This setting can only be changed while parked.": "Ce réglage ne peut être modifié que lorsque le véhicule est stationné.",
    Default: "Par défaut", "Loading...": "Chargement...", "No options available": "Aucune option disponible",
    "Working...": "En cours...", Run: "Exécuter", Manage: "Gérer", Close: "Fermer", Stock: "Origine",
  },
  ko: {
    English: "영어", Spanish: "스페인어", French: "프랑스어", Korean: "한국어", Chinese: "중국어",
    Home: "홈", Toggles: "토글", Tools: "도구", Recordings: "녹화",
    Bluetooth: "블루투스", "Cameras & Monitoring": "카메라 및 모니터링", Galaxy: "Galaxy",
    "Logs & Diagnostics": "로그 및 진단", "Model Manager": "모델 관리자",
    "Navigation & Maps": "내비게이션 및 지도", "System Tools": "시스템 도구",
    "Model Laboratory": "모델 연구소", Plots: "플롯", "Testing Ground": "테스트 공간",
    "Theme Maker": "테마 만들기", "Tuning, Plots & Testing": "튜닝, 플롯 및 테스트",
    "Vehicle Controls": "차량 제어", Main: "메인", Offline: "오프라인", Parked: "주차됨",
    Back: "뒤로", Menu: "메뉴", "Galaxy home": "Galaxy 홈", "Search toggles...": "토글 검색...",
    "Search toggles": "토글 검색", "Clear search": "검색 지우기", "Dark mode": "다크 모드",
    "Light mode": "라이트 모드", "Switch to dark mode": "다크 모드로 전환", "Switch to light mode": "라이트 모드로 전환",
    Settings: "설정", Language: "언어", "Select language": "언어 선택", Advanced: "고급",
    "result(s)": "개 결과",
    "Galaxy uses English when no language is selected.": "언어를 선택하지 않으면 Galaxy는 영어를 사용합니다.",
    "Language updated.": "언어가 업데이트되었습니다.", "Unable to save language.": "언어를 저장할 수 없습니다.",
    "Loading configuration...": "설정을 불러오는 중...", "No settings available.": "사용 가능한 설정이 없습니다.",
    "No settings in this section.": "이 섹션에 설정이 없습니다.", "Locked:": "잠김:", "Step:": "단계:",
    "This setting can only be changed while parked.": "이 설정은 주차 중에만 변경할 수 있습니다.",
    Default: "기본값", "Loading...": "로드 중...", "No options available": "사용 가능한 옵션이 없습니다",
    "Working...": "처리 중...", Run: "실행", Manage: "관리", Close: "닫기", Stock: "기본",
  },
  "zh-CHS": {
    English: "英语", Spanish: "西班牙语", French: "法语", Korean: "韩语", Chinese: "中文",
    Home: "主页", Toggles: "开关", Tools: "工具", Recordings: "录制内容",
    Bluetooth: "蓝牙", "Cameras & Monitoring": "摄像头和监控", Galaxy: "Galaxy",
    "Logs & Diagnostics": "日志和诊断", "Model Manager": "模型管理器",
    "Navigation & Maps": "导航和地图", "System Tools": "系统工具",
    "Model Laboratory": "模型实验室", Plots: "图表", "Testing Ground": "测试区",
    "Theme Maker": "主题制作器", "Tuning, Plots & Testing": "调校、图表和测试",
    "Vehicle Controls": "车辆控制", Main: "主菜单", Offline: "离线", Parked: "已停车",
    Back: "返回", Menu: "菜单", "Galaxy home": "Galaxy 主页", "Search toggles...": "搜索开关...",
    "Search toggles": "搜索开关", "Clear search": "清除搜索", "Dark mode": "深色模式",
    "Light mode": "浅色模式", "Switch to dark mode": "切换到深色模式", "Switch to light mode": "切换到浅色模式",
    Settings: "设置", Language: "语言", "Select language": "选择语言", Advanced: "高级",
    "result(s)": "个结果",
    "Galaxy uses English when no language is selected.": "未选择语言时，Galaxy 将使用英语。",
    "Language updated.": "语言已更新。", "Unable to save language.": "无法保存语言。",
    "Loading configuration...": "正在加载配置...", "No settings available.": "没有可用设置。",
    "No settings in this section.": "此部分没有设置。", "Locked:": "已锁定：", "Step:": "步长：",
    "This setting can only be changed while parked.": "此设置只能在车辆停放时更改。",
    Default: "默认值", "Loading...": "加载中...", "No options available": "没有可用选项",
    "Working...": "处理中...", Run: "运行", Manage: "管理", Close: "关闭", Stock: "原厂",
  },
}

function storageValue() {
  try { return window.localStorage.getItem(STORAGE_KEY) || "en" } catch (e) { return "en" }
}

export function normalizeLanguage(value) {
  const code = String(value || "").trim().replace(/^main_/i, "")
  return SUPPORTED_CODES.has(code) ? code : "en"
}

export const languageState = reactive({ code: normalizeLanguage(storageValue()) })

export function setLanguage(value) {
  const code = normalizeLanguage(value)
  languageState.code = code
  try { window.localStorage.setItem(STORAGE_KEY, code) } catch (e) { /* storage can be unavailable in private webviews */ }
  if (typeof document !== "undefined") document.documentElement.lang = code === "zh-CHS" ? "zh-CN" : code
  return code
}

export function t(key, fallback = key) {
  const source = String(key ?? "")
  return TRANSLATIONS[languageState.code]?.[source] || fallback || source
}

setLanguage(languageState.code)
